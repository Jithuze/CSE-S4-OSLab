#include<stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();


int main(){
  int i,j;
  input();
  show();
  cal();
  return 0;
}

void input(){
  int i,j;
  printf("Enter the no of processes : \t");
  scanf("%d",&n);
  printf("Enter the no of resources instances : \t");
  scanf("%d",&r);
  printf("Enter the max matrix \n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      scanf("%d",&max[i][j]);
    }
  }
  printf("Enter the allocation matrix\n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      scanf("%d",&alloc[i][j]);
    }
  }
  printf("Enter the resources available \n");
  for(j=0;j<r;j++){
    scanf("%d",&avail[j]);
  }
}

void show(){
  int i,j;
  printf("Process\tAllocation\tMax\tAvailable\t");
  for(i=0;i<n;i++){
    printf("\nP%d\t",i+1);
    for(j=0;j<r;j++){
      printf("%d",alloc[i][j]);
    }
    printf("\t\t");
    for(j=0;j<r;j++){
      printf("%d",max[i][j]);
    }
    printf("\t");
    if(i==0){
      for(j=0;j<r;j++)
        printf("%d",avail[j]);
    }
  }
}

void cal(){
  int finish[100],temp,need[100][100],flag=1,k,cl=0;
  int saf[100];
  int i,j;
  for(i=0;i<n;i++){
    finish[i]=0;
  }
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  printf("\n");
  while(flag){
    flag=0;
    for(i=0;i<n;i++){
      int c=0;
      for(j=0;j<r;j++){
        if((finish[i]==0)&&(need[i][j]<=avail[j])){
          c++;
          if(c==r){
            for(k=0;k<r;k++){
              avail[k]+=alloc[i][j];
              finish[i]=1;
              flag=1;
            }
            printf("P%d->",i+1);
          }
        }
      }
    }
  }
  for(i=0;i<n;i++){
    if(finish[i]==1){
      cl++;
    }
    else{
      printf("P%d->",i+1);
    }
  }
  if(cl==n){
    printf("\nThe System is in safe state");
  }
  else{
    printf("System is in unsafe state");
  }
}
