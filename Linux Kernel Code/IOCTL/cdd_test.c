#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char ch = 0;
	char w_buf[10] = "welcome";
	char r_buf[10] = {};

	int fd = open("/dev/cdd",O_RDWR);
	if(fd==-1){
		perror("open");
		exit(-1);
	}

	printf("open successed!fd = %d\n",fd);

	while(1){
		ch = getchar();
		getchar();

		if(ch=='q')
			break;

		switch(ch){
			case 'r':
				read(fd,r_buf,sizeof(r_buf));
				printf("r_buf = %s\n",r_buf);
				break;
			case 'w':
				write(fd,w_buf,sizeof(r_buf));
				break;
			default:
				printf("error input!\n");
				break;
		}

		sleep(1);
	}

	close(fd);
	return 0;
}
