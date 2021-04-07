#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int child;
	mkfifo("C5S7FM", S_IRUSR | S_IWUSR);
	child = fork();
	if (child > 0){
		char s[1024];
		int fd;
		fd = open("C5S7FM", O_RDONLY);
		read(fd, s, sizeof(s));
		printf("%s", s);

		close(fd);
		unlink("C5S7FM");
	}
	else if (child == 0){
		int fd;
		fd = open("C5S7FM", O_WRONLY);
		write(fd, "Orosz Daniel\n", 100);
	}
	return 0;
}