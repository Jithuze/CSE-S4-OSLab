#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
static char message[] = "this is a testing";
int main(){
	int fd;
	char buffer[80];
	fd = open("newfile.txt",O_RDWR|O_CREAT,S_IREAD|S_IWRITE);
	if(fd!=-1){
		printf("newfile.txt opened for read/write access ");
		write(fd,message,sizeof(message));
		lseek(fd,0l,0);
		if(read(fd,buffer,sizeof(message))==sizeof(message))
			printf("\"%s\" was written to newfile.txt\n",buffer);
		else
			printf("Error");
		}
	else{
		close(fd);
		printf("newfile.txt already exists ");
		}
	exit(0);
	}

