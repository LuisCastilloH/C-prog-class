#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1025

int main() {
    int fd;
    // 1. Crear socket TCP
    fd = socket(AF_INET, SOCK_STREAM, 0);
    // 2. Asignar puerto a socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    // 3. Poner al socket en modo escucha (bind)
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Unable to bind\n");
        close(fd);
        exit(1);
    }
    if (listen(fd, 1) == -1) {
        perror("Unable to listen\n");
    }
    // 4. Repetir
    int connfd;
    struct sockaddr_in cli_addr;
    char *buffer = (char *)malloc(10000*sizeof(char));
    while(1) { 
        printf("Entro\n");
        // 4.1 Aceptar nueva conexion
        socklen_t cli_addr_len = sizeof(cli_addr);
        /*connfd = accept(fd, (struct sockaddr *)&cli_addr, &cli_addr_len);*/
        connfd = accept(fd, NULL, NULL);
        if (connfd == -1) {
            perror("Unable to connect\n");
        }
        printf("Acepto\n");
        // 4.2 Comunicacion
        read(connfd, buffer, 10000);
        if(!strcmp(buffer, "F")) {
            printf("%s", buffer);
            printf("termino");
            break;
        }
        printf("%s\n", buffer);
        char *str = "OK";
        write(connfd, str, strlen(str));
    }
    free(buffer);
    // 4.3 Cerrar conexion
    close(connfd);
    close(fd);
    printf("Fin\n");

    return 0;
}
