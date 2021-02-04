#include<stdio.h>
#include<conio.h>

#define Max 10
int push(int [],int);
int pop(int [],int);
void display(int [],int);
void peek(int [],int);
int main()
{ 
 int stack[Max],top=-1,ch;
 do
 { 
   printf("\n Menu \n 1 push \n 2 pop \n3 Display  \n4 Peek ");
   printf("\nEnter your choice : ");
   scanf("%d",&ch);
   switch(ch)
      { 
        case 1:  
           top= push(stack,top);
           break;
        case 2:
           top= pop(stack,top);
           break;
        case 3:
           display(stack,top);
           break;
        case 4:
           peek(stack,top);
           break;
      }
  }while(ch<5);
  return 0;
}

int push(int stack[],int top)
  {
     if(top >= Max-1){
     printf("Stack is full");
     }
     else{
       top++;
       scanf("%d",&stack[top]);
     }
     return top;
  }

int pop(int stack[],int top)
  {
    if(top < 0){
     printf("Stack is empty");
     }
     else{
       printf("Popped element is %d",stack[top]);
       top--;
     }
     return top;
  }

void display(int stack[],int top)
  {
    int temp;
    if(top < 0){
     printf("Stack is empty");
     }
     else{
      for(int i=top;i>-1;i--){
         printf("\n%d",stack[i]);
       }
     }
  }

void peek(int stack[],int top)
  {
    if(top < 0){
     printf("Stack is empty");
     }
     else{
        printf("\nValue of element at top is %d",stack[top]);
     }
  }