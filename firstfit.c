#include<stdio.h>
int main()
{
  int i,j,blockno,blocksize[10],processno,processsize[10];
  printf("Enter the number of free blocks\n");
  scanf("%d",&blockno);
  printf("Enter the size of free blocks\n");
  for(i=0;i<blockno;i++)
  scanf("%d",&blocksize[i]);
  printf("Enter the number of processes\n");
  scanf("%d",&processno);
  printf("Enter the size of processes\n");
  for(i=0;i<processno;i++)
  scanf("%d",&processsize[i]);
  for(i=0;i<blockno;i++)
  printf("size of free block %d: %d\n",i+1,blocksize[i]);
  printf("\n\n");
  for(i=0;i<processno;i++)
  printf("size of process %d: %d\n",i+1,processsize[i]);
  printf("\n");
  printf("FIRST FIT MEMORY ALLOCATION\n\n");
  printf("Processno\tAllocated block\t\tAllocated size\t\tFragment in that block\n");
  i=0;
  while(i<processno)
  {
    for(j=0;j<blockno;j++)
    {
      if(processsize[i]<=blocksize[j])
      {
        blocksize[j]-=processsize[i];
        break;
      }
    }
                        printf("%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t\t%d\n",i+1,j+1,processsize[i],blocksize[j]);
                        i++;
            }
            return 0;
}
