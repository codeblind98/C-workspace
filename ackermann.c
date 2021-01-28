#include<stdio.h>
#include<conio.h>

int A(int,int);
int main()
{
    int sum;
    sum=A(1,0);
    printf("\nThe answer is %d ",sum);
    return 0;
}

int A(int m,int n)
{
 if(m==0){
    return n+1;
 }

  if(m>0 && n==0){
    return A(m-1,1);
 }

  if(m>0 && n>0){
    return A(m-1,A(m,n-1));
 }
}
