#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#define PORTNUMBER 12345
/*
    Función de generación aleatoria de caracteres:
    https://www.codeproject.com/Questions/640193/Random-string-in-language-C
*/
char *randstr(const int);
int main(void){

    char buf[10];
    int _socket, cant_recv, new_socket, len;
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
        printf("Cliente conectado\n");
        while ((cant_recv = recv(new_socket, buf, sizeof(buf), 0)) > 0){
            write(new_socket, randstr(cant_recv), cant_recv);
        }
    }

    close(new_socket);
    close(_socket);
    exit(0);
}

char *randstr(const int len) {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char *s = malloc((len * sizeof(char)) + 1);

    srand(time(NULL));
    for (int i = 0; i < len-1; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len-1] = '\n';
    s[len] = 0;
    return s;
}
/* PrimerServidorTCP.c
Servicio: Las cadenas de texto recibidas de un Cliente son enviadas a la salida estándar.
Nota: Por simplicidad del código no se realiza ningún tipo de control de errores. No obstante
el servidor es totalmente funcional.
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PORTNUMBER 12345
#define BUFF_SIZE 1024

int main(void){

    char buf[BUFF_SIZE];
    int _socket, cant_recv, new_socket, len;
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
            /*write(1, buf, cant_recv);*/
            /*hacemos eco*/
            /*write(new_socket, buf, cant_recv);*/
            printf("Mensaje recibido: %s", buf);
        }
    }

    close(new_socket);
    close(_socket);
    exit(0);
}
