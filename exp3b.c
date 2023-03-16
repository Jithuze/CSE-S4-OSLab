#include<stdio.h>
#include<unistd.h>

main(){
	int pid,pid1,pid2;
	pid = fork();
	if(pid == -1){
		printf("Error in process Creation");
		exit(1);
		}
	if(pid!=0){
		pid1 = getpid();
		printf("the parent process ID is %d ",pid1);
		}
	else{
		pid2 = getpid();
		printf("\nthe child process ID is %d ",pid2);
		}
	}

