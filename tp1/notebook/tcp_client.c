#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
 
#define HOST "127.0.0.1"
#define PORTNUMBER 12345
#define BUFF_SIZE 1024

int check_arg(int, char *, char *);

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char msj[BUFF_SIZE], rta_server[BUFF_SIZE];
     
    //Creamos el socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        perror("*** ERROR AL CREAR EL SOCKET ***");
        return 1;
    }
     
    server.sin_addr.s_addr = inet_addr(HOST);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORTNUMBER);
 
    //Nos conectamos al servidor
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("*** ERROR AL CONECTAR AL SERVIDOR ***");
        return 1;
    }
     
    printf("Conectado a %s:%d\n", HOST, PORTNUMBER);
     
    while(1)
    {
         
        //enviamos el mensaje al servidor
        printf("Ingrese su mensaje: ");
        fgets(msj, BUFF_SIZE, stdin);

        if( send(sock, msj, strlen(msj)+1, 0) < 0)
        {
            perror("*** ERROR AL ENVIAR EL MENSAJE AL SERVIDOR***");
            return 1;
        }
         
        //recibimos la respuesta del servidor
        if(check_arg(argc, argv[1], "-e") || check_arg(argc, argv[1], "--echo")){
            if( recv(sock, rta_server, BUFF_SIZE, 0) < 0)
            {
                perror("*** ERROR AL RECIBIR RESPUESTA DEL SERVIDOR ***");
                return 1;
            }
             
            printf("Respuesta del servidor: %s\n", rta_server);
        }
        bzero(msj, BUFF_SIZE);
    }
     
    /*Cerramos el socket y finalizamos*/
    close(sock);
    return 0;
}

int check_arg(int argc, char *argv, char *arg){
    return argc == 2 && strcmp(argv, arg) == 0;
}