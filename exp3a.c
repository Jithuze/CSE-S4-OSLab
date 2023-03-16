#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

struct dirent *dptr;

main(){
	char buff[100];
	DIR *dirp;
	printf("Enter Directory Name ");
	scanf("%s",buff);
	if((dirp = opendir(buff))==NULL){
		printf("The Given Directory Does Not Exists ");
		exit(1);
		}
	while(dptr=readdir(dirp)){
		printf("%s\n",dptr->d_name);
		}
	close(dirp);
}

