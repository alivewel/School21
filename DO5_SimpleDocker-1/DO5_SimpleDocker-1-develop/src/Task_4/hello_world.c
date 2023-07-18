#include <fcgi_stdio.h>
#include <stdlib.h>

int main(void) {
    while (FCGI_Accept() >= 0) { //  функция создает новый процесс для обработки этого соединения, и оригинальный процесс может продолжать прослушивание входящих соединений.
        printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\nHello World!\n");
    }
    return 0;
}
