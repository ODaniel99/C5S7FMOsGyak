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
    char * fifoname = "/tmp/fifoname";

    mkfifo(fifoname, S_IWUSR | S_IRUSR);

    char number[40], number2[40];
    double power;

    while(1){
        fd = open(fifoname, O_WRONLY);
        fgets(number, 40, stdin);
        write(fd, number, strlen(number)+1);
        close(fd);

        fd = open(fifoname, O_RDONLY);
        read(fd, number2, sizeof(number2));
        power = atof(number2);
        double paw = power * power;
        printf("A szam negyzete: %f\n", paw);
        close(fd);
    }
    return 0;
}
