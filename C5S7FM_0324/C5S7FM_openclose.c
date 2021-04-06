#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file, sz;
	char *data = (char *) calloc(100, sizeof(char));

	file = open("C5S7FM.txt", 0_RDWR);
	if (file < 0){
		perror("r1");
		exit(1);
	}

	sz = write(file, "Orosz Daniel Uzemmernok-informatikus C5S7FM", 42);
	close(file);

	file = open("C5S7FM.txt", 0_RDONLY);

	sz = read(file, data, 100);
	data[sz] = '\0';
	printf("Bytes read: %d\nTest read: % s\n", sz, data);

	lseek(file, 0, SEEK_SET);

	return 0;
}