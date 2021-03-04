#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void bubbleSort(int [],int);
void selectionSort(int [],int);
void insertionSort(int [],int);
void display(int [],int);

int main(){
	int len,i,opt;
	printf("\nEnter length of the array : ");
	scanf("%d",&len);
    int arr[len];
	for(i=0;i<len;i++)
	   scanf("%d",&arr[i]);
	   
	while(1){
		printf("\nEnter your choice \n 1 BUBBLE SORT \n 2 SELECTION SORT \n 3 INSERTION SORT \n 4 EXIT\n");
	     scanf("%d",&opt);
	     if(opt==1)
	      bubbleSort(arr,len);
	     else if(opt==2)
	      selectionSort(arr,len);
	     else if(opt==3)
	       insertionSort(arr,len);
	     else
	      break;
    }
 return 0;
 }
 
 void bubbleSort(int a[],int len){
 	int i,j,temp;
 	for(i=0;i<len-1;i++){
 		for(j=0;j<(len-1-i);j++){
 			if(a[j]>a[j+1]){
 				temp=a[j+1];
 				a[j+1]=a[j];
 				a[j]=temp;
			 }
		 }
	 }
	 printf("\n------printing array sorted by bubble sort--------\n");
	 display(a,len);
 }
 
 void selectionSort(int a[],int len){
 	int i,j,min=0,pos=0;
 	for(i=0;i<len-1;i++){
 		min=a[i];
 		pos=i;
 		for(j=i+1;j<len-1;j++){
 			if(a[j]<min){
 				min=a[j];
 				pos=j;
			 }
		 }
	 }
	 printf("\n------printing array sorted by selection sort--------\n");
	 display(a,len);
 }
 
 void insertionSort(int a[],int len){
 	int i,j,t=0;
 	for(i=1;i<len;i++){
 		t=a[i];
 		j=i-1;
 		while(j>=0&&t<a[j]){
 			a[j+1]=a[j];
 			j--;
		 }
		 a[j+1]=t;
	 }
	 printf("\n------printing array sorted by insertion sort--------\n");
	 display(a,len);
 }
 
 void display(int a[],int len){
 	int i;
 	for(i=0;i<len;i++)
 	 printf("%d\t",a[i]);
 }
