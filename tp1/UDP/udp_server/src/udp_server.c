#include<stdio.h>
#include<strings.h> 
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define BUF_SIZE 512  //Max length of buffer
#define PORTNUMBER 12345   //The port on which to listen for incoming data
 
void die(char *_socket)
{
    perror(_socket);
    exit(1);
}
 
int main(void)
{
    struct sockaddr_in direcc, si_other;
     
    int _socket, slen = sizeof(si_other) , recv_len;
    char buf[BUF_SIZE];
     
    //create a UDP socket
    if ((_socket=socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        die("socket");
    }
     
    // zero out the structure
    bzero((char *) &direcc, sizeof(direcc));
    /*memset((char *) &direcc, 0, sizeof(direcc));*/
     
    direcc.sin_family = AF_INET;
    direcc.sin_port = htons(PORTNUMBER);
    direcc.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to port
    if( bind(_socket , (struct sockaddr*)&direcc, sizeof(direcc) ) == -1)
    {
        die("bind");
    }
     
    //keep listening for data
    while(1)
    {
        printf("Waiting for data...");
        fflush(stdout);
         
        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(_socket, buf, BUF_SIZE, 0, (struct sockaddr *) &si_other, &slen)) == -1)
        {
            die("recvfrom()");
        }
         
        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);
         
        //now reply the client with the same data
        if (sendto(_socket, buf, recv_len+1, 0, (struct sockaddr*) &si_other, slen) == -1)
        {
            die("sendto()");
        }
    }
 
    close(_socket);
    return 0;
}
