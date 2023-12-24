#include<stdio.h>
#include<stdlib.h>
int main(int arc,char *argv[]){
	int counter=0;
	int rc=fork();
	if(rc<0){
		printf("Fork Failed\n");
	}
	else if(rc==0){
		counter+=35;
		printf("I am in Child Process %d\nCounter in child is %d\n",getpid(),counter);
	}
	else{
		wait();
		counter+=27;
		printf("I am in parent process %d\nCounter in parent is %d\n",getpid(),counter);
	}

	return 0;
}


