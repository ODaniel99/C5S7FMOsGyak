#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int main()
{
    int fd;
    char * fifoname = "/tmp/fifoname";

    mkfifo(fifoname, S_IWUSR | S_IRUSR);

    char number[40], number2[40];

    while(1){
        fd = open(fifoname, O_RDONLY);
        read(fd, number, 40);
        printf("Kapott szam: %s", number);
        close(fd);

       /* double power = atof(number);
        double ret = power * power;
        memcpy(number2, &ret, sizeof(ret));*/

        fd = open(fifoname, O_WRONLY);
        write(fd, number, strlen(number));
        close(fd);
    }
    return 0;
}
