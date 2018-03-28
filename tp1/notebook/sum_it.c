#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PORTNUMBER 12345
#define BUFF_SIZE 1024
#define MSG_SIZE 128

int main(void){

    char buf[BUFF_SIZE], msg[MSG_SIZE];
    int _socket, cant_recv, 
        new_socket, len,
        sum1, sum2;
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
        new_socket = accept(_socket, (struct sockaddr *) &direcc, (socklen_t *) &len);
        while ((cant_recv = recv(new_socket, buf, BUFF_SIZE, 0)) > 0){
            printf("Mensaje recibido: %s", buf);

            /*
             * Si el mensaje recibido tiene el formato correcto,
             * devolvemos la suma de los parámetros 
             */
            if (sscanf(buf, "%d+%d", &sum1, &sum2) == 2){
                sprintf(msg, "%d+%d = %d\n", sum1, sum2, sum1+sum2);
            } else {
                sprintf(msg, "Formato incorrecto\nUSO: NUM+NUM\n");
            }
            write(new_socket, msg, strlen(msg)+1);
            bzero(buf, BUFF_SIZE);
            bzero(msg, MSG_SIZE);
        }
    }

    close(new_socket);
    close(_socket);
    exit(0);
}