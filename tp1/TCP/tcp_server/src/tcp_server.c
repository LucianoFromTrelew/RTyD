/* PrimerServidorTCP.c
Servicio: Las cadenas de texto recibidas de un Cliente son enviadas a la salida estándar.
Nota: Por simplicidad del código no se realiza ningún tipo de control de errores. No obstante
el servidor es totalmente funcional.
*/
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

int main(void){

    char buf[BUFF_SIZE];
    int _socket, cant_recv, new_socket, len;
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
        /*Aceptamos clientes; devuelve un nuevo socket*/
        new_socket = accept(_socket, (struct sockaddr *) &direcc, (socklen_t *) &len);
        while ((cant_recv = recv(new_socket, buf, BUFF_SIZE, 0)) > 0){
            printf("Mensaje recibido: %s", buf);
        }
    }

    /*Cerramos sockets y finalizamos*/
    close(new_socket);
    close(_socket);
    exit(0);
}
