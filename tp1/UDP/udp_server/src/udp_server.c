#include<stdio.h>
#include<strings.h> 
#include<string.h> 
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define BUF_SIZE 1024
#define PORTNUMBER 12345
 
int main(void)
{
    struct sockaddr_in direcc, client;
     
    int _socket, slen = sizeof(client) , recv_len;
    char buf[BUF_SIZE];
     
    //creamos el socket UDP
    if ((_socket=socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("*** ERROR AL CREAR EL SOCKET ***");
        return 1;
    }
    /*limpiamos la estructura de datos*/
    bzero((char *) &direcc, sizeof(direcc));
     
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //asociamos el socket a una dirección y un puerto
    if( bind(_socket , (struct sockaddr*)&direcc, sizeof(direcc) ) == -1)
    {
        perror("*** ERROR AL ASOCIAR EL SOCKET ***");
        return 1;
    }
     
    //esperamos datos...
    while(1)
    {
        //recibimos datos
        if ((recv_len = recvfrom(_socket, buf, BUF_SIZE, 0, (struct sockaddr *) &client, (socklen_t *) &slen)) == -1)
        {
            perror("*** ERROR AL RECIBIR DATOS ***");
            return 1;
        }
         
        printf("%s:%d dice: %s", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buf);
         
        //hacemos eco
        if (sendto(_socket, buf, strlen(buf)+1, 0, (struct sockaddr*) &client, slen) == -1)
        {
            perror("*** ERROR AL ENVIAR DATOS ***");
            return 1;
        }

        /*limpiamos el buffer de entrada*/
        bzero(buf, BUF_SIZE);
    }
 
    close(_socket);
    return 0;
}
