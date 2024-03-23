#include<stdio.h>
#include<stdlib.h>
#include <time.h> 
#include<omp.h>

void merge(int array[],int low,int mid,int high)
{
  int temp[100000];
  int i,j,k,m;
  j=low;
  m=mid+1;
  for(i=low; j<=mid && m<=high ; i++)
  {
     if(array[j]<=array[m])
     {
         temp[i]=array[j];
         j++;
     }
     else
     {
         temp[i]=array[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=high; k++)
     {
         temp[i]=array[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        temp[i]=array[k];
        i++;
     }
  }
  for(k=low; k<=high; k++)
     array[k]=temp[k];
}


void mergesort(int array[],int low,int high)
{
 int mid;
 if(low<high)
 {
   mid=(low+high)/2;
   mergesort(array,low,mid);
   mergesort(array,mid+1,high);
   merge(array,low,mid,high);
 }
}


int main(int argc,char* argv[])
{
 int array[100000];
 int i,j,size;
 size = atoi(argv[1]);
 
 for(i=size-1,j=0; i>-1,j<size; i--,j++)
 {
   array[j] = i;
 }
 
 /*
 printf("Un-sorted Elements as follows:\n");
 for(i=0; i<size; i++)
    printf("%d ",array[i]);
 printf("\n");
 */

 double time_spent = 0.0;
 clock_t begin = clock();
 mergesort(array,0,size-1);
 clock_t end = clock();
 time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 printf("The elapsed time is %f seconds\n", time_spent);
 
 //Commented Code is run to check whether code is working properly or not
 
 /*
 printf("Sorted Elements as follows:\n");
 for(i=0; i<size; i++)
    printf("%d ",array[i]);
 printf("\n");
 */
 return 0;
}