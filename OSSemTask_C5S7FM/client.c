#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char * fifoname = "/tmp/myfifo";
    mkfifo(fifoname , S_IWUSR | S_IRUSR);
    char number[40];
    double power;

    while(1){
        fd = open(fifoname , O_WRONLY);
        fgets(number, 40, stdin);
        write(fd, number, strlen(number)+1);
        close(fd);

        fd = open(fifoname , O_RDONLY);
        read(fd, number, sizeof(number));
        power = atof(number);
        double paw = power * power;
        printf("A szam negyzete: %.0f\n", paw);
        close(fd);
    }
    return 0;
}