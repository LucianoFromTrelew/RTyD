#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define SERVER "127.0.0.1"
#define BUFF_SIZE 1024
#define PORTNUMBER 12345
 
int main(void)
{
    struct sockaddr_in server;
    int _socket, slen=sizeof(server);
    char res[BUFF_SIZE];
    char msj[BUFF_SIZE];
 
    if ((_socket=socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("*** ERROR AL CREAR EL SOCKET ***");
        return 1;
    }
 
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORTNUMBER);
     
    while(1)
    {
        printf("Ingrese su mensaje: ");
        fgets(msj, BUFF_SIZE, stdin);
         
        //enviamos el mensaje
        if (sendto(_socket, msj, strlen(msj)+1, 0, (struct sockaddr *) &server, slen)==-1)
        {
            perror("*** ERROR AL ENVIAR MENSAJE ***");
            return 1;
        }
         
        //recibimos respuesta del servidor
        if (recvfrom(_socket, res, BUFF_SIZE, 0, (struct sockaddr *) &server, (socklen_t *) &slen) == -1)
        {
            perror("*** ERROR AL RECIBIR RESPUESTA ***");
            return 1;
        }
         
        printf("Respuesta del servidor: %s", res);
        bzero(res, BUFF_SIZE);
        bzero(msj, BUFF_SIZE);
    }
 
    close(_socket);
    return 0;
}
