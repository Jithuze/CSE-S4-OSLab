#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	fork();
	fork();
	printf("Hello PID = %d\n",getpid());

	return 0;
}
