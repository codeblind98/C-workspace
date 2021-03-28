#include<stdio.h>

void quickSort(int [],int,int);
int partition(int [],int ,int);
void swap(int [],int,int);

int main(){
	int range,i;
	printf("\nEnter the range of the array");
	scanf("%d",&range);
	int a[range];
	for(i=0;i<range;i++)
	  scanf("%d",&a[i]);
	  
	quickSort(a,0,range-1);
	for(i=0;i<range;i++)
	  printf("%d\t",a[i]);  
  return 0;	
}

void quickSort(int a[],int lb,int ub){
	if(lb<ub)
	  {
	  	int loc=partition(a,lb,ub);
	  	quickSort(a,lb,loc-1);
	  	quickSort(a,loc+1,ub);
	  }
}

int partition(int a[],int lb,int ub){
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end){
		while(a[start]<=pivot)
		    start++;
		while(a[end]>pivot)
		    end--;
		if(start<end)
		   swap(a,start,end);
    }
    swap(a,lb,end);
    return end;
}

void swap(int a[],int lb ,int ub){
	int temp;
	temp=a[lb];
	a[lb]=a[ub];
	a[ub]=temp;
}
