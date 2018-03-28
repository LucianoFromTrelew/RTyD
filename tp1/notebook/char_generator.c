#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <syscall.h>
#include <sys/wait.h>

#define PORTNUMBER 12345
#define BUFF_SIZE 64
#define WAIT_TIME 50000


int randrange(int min, int max);
int write_socket(int, int);
void handle_sigpipe(int);

int main(void){

    int _socket, new_socket, len;
    struct sockaddr_in direcc;
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &direcc, sizeof(direcc));

    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    bind(_socket, (struct sockaddr *) &direcc, len);
    listen(_socket, 5);

    /*
     * añadimos una manejador para la señal SIGPIPE
     * que va a ser la recibida cuando el cliente se desconecte
     */
    signal(SIGPIPE, handle_sigpipe);

    srand(time(NULL));
    /*el servidor no muere cuando se desconecta el cliente */
    while(1){
        new_socket = accept(_socket, (struct sockaddr *) &direcc, (socklen_t *) &len);
        while(write_socket(new_socket, WAIT_TIME) > 0){ }
    }

    close(new_socket);
    close(_socket);
    exit(0);
}

int write_socket(int sckt, int wait){
    char buf[BUFF_SIZE];
    usleep(wait);
    sprintf(buf, "%d\n", randrange(0, 99));
    return write(sckt, buf, strlen(buf)+1);
}

void handle_sigpipe(int signum){
    signal(SIGPIPE, handle_sigpipe);
}

int randrange(int min, int max){
    return (rand() % (max + 1 - min) + min);
}