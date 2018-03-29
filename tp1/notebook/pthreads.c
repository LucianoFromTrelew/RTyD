#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PORTNUMBER 12345
#define BUFF_SIZE 1024
#define MAX_PTHREADS 256

void *handle_client(void *);

int main(void){

    pthread_t clients[MAX_PTHREADS];
    int _socket, new_socket, len;
    struct sockaddr_in direcc;
    /*Creamos el socket TCP (SOCK_STREAM)*/
    if((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("*** ERROR AL CREAR EL SOCKET ***");
        return 1;
    }

    /*limpiamos la estructura de datos*/
    bzero((char *) &direcc, sizeof(direcc));

    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);

    len = sizeof(struct sockaddr_in);
    /*Lo asociamos a una dirección y un puerto*/
    if(bind(_socket, (struct sockaddr *) &direcc, len) < 0){
        perror("*** ERROR AL ASOCIAR EL SOCKET ***");
        return 1;
    }
    /*Lo ponemos a la escucha de clientes que se quieran conectar*/
    listen(_socket, 5);

    /*el servidor no muere cuando se desconecta el cliente */
    while(1){
        for (int i=0; i<MAX_PTHREADS; i++){
            /*Aceptamos clientes; devuelve un nuevo socket*/
            new_socket = accept(_socket, (struct sockaddr *) &direcc, (socklen_t *) &len);
            if((pthread_create(&clients[i], NULL, handle_client, (void *) &new_socket)) != 0){
                perror("*** ERROR AL ATENDER UN CLIENTE ***");
                return 1;
            }
        }
    }

    /*Cerramos sockets y finalizamos*/
    close(_socket);
    exit(0);
}

void *handle_client(void *arg){
    int _socket = *(int *)arg;
    char buf[BUFF_SIZE];
    while ((recv(_socket, buf, BUFF_SIZE, 0)) > 0){
        printf("Mensaje recibido: %s", buf);
        bzero(buf, BUFF_SIZE);
    }
    close(_socket);
    pthread_exit((void *)0);
}