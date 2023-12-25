#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[]){
	char *buffer[1000];
	int file = open("test.txt",O_CREAT|O_APPEND|O_RDWR);
	int rc = fork();
	if(rc == 0){
		printf("In the child process with pid %d\n",getpid());
		char *buff="Written by child\n";
		write(file,buff,strlen(buff));
	}
	else{
		printf("In the parent process with pid %d\n",rc);
		char *buff="Written by parent\n";
		write(file,buff,strlen(buff));
	}
	close(file);
	return 0;
}

