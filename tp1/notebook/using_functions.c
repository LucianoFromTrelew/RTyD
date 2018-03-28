#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define PORTNUMBER 12345
#define BUFF_SIZE 1024
int accept_client(int, struct sockaddr *, socklen_t *);
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

    /*el servidor no muere cuando se desconecta el cliente */
    while(1){
        accept_client(_socket, (struct sockaddr *) &direcc, (socklen_t *) &len);
    }

    close(_socket);
    exit(0);
}

int accept_client(int sckt, struct sockaddr* addr, socklen_t *len){
    int new_socket = accept(sckt, addr, len);
    int cant_recv;
    char buf[BUFF_SIZE];
    while ((cant_recv = recv(new_socket, buf, sizeof(buf), 0)) > 0){
        printf("Mensaje recibido: %s", buf);
        bzero(buf, BUFF_SIZE);
    }
    close(new_socket);

    return 0;
}