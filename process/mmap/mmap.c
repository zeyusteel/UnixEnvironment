#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char *p = NULL;
	int fd;

	fd = open("testmap",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd == -1){
		perror("open error\n");
	}
//文件拓展为11
/*
	lseek(fd,10,SEEK_END);
	write(fd,"\0",1);
*/

	ftruncate(fd,20);//文件拓展为20
	int len = lseek(fd,0,SEEK_END);//文件长度	

	p = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(p == MAP_FAILED){
		perror("mmap error");
	}

	strcpy(p,"hello mmap");
	printf("%s\n",p);

	int ret = munmap(p,len);
	if(ret == -1){
		perror("munmap error");
	}

	close(fd);
	return 0;
} 
