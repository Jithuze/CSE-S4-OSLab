#include<stdio.h>
void main(){
	int i=0,j=0,b[20],g[20],p[20],pr[20],w[20],t[20],n=0,m;
	float avgw=0,avgt=0;
	printf("Enter Number Of Processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Process Id : ");
		scanf("%d",&p[i]);
		printf("Burst Time : ");
		scanf("%d",&b[i]);
		printf("Priority : ");
		scanf("%d",&pr[i]);
	}
	
	int temp=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n;j++){
			if(pr[j]>pr[j+1]){
				temp = pr[j];
				pr[j] = pr[j+1];
				pr[j+1] = temp;
				
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			
				temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			
			}
		}
	}
	
	g[0]=b[0];
	for(i=1;i<n;i++){
		g[i]=g[i-1]+b[i];	
	}
	for(i=0;i<n;i++){
		t[i]=g[i];
		w[i] = t[i]-b[i];
		avgw += w[i];
		avgt += t[i];

	}
	avgw = avgw/n;
	avgt = avgt/n;
	
	printf("PID\tBT\tPRT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],b[i],pr[i],g[i],t[i],w[i]);
		
	}
	printf("Average Wait Time : %f ",avgw);
	printf("Average TurnAround Time : %f ",avgt);	
}
