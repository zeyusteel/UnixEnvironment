#include <stdio.h>

extern char **environ;

int main(int argc,char *argv[])
{
	int i;
	for(int i=0;environ[i];i++){
		printf("%s\n",environ[i]);
	}
	return 0;
}
