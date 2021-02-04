#include<conio.h>
#include<stdio.h>

#define Max 10

int enqueue(int [],int,int);
int dequeue(int [],int,int);
void display(int [],int,int);
void peek(int [],int);
int main()
{ 
 int queue[Max],front=-1,rear =-1, ch,temp;
do
{ 
printf("\n Menu \n 1 Insert  \n 2 Remove  \n 3 Display  \n 4 Peek  \n 5 exit ");  // Menu
printf("\nEnter your choice : ");
scanf("%d",&ch);
 switch(ch)
  { 
    case 1:  
          temp=enqueue(queue,front,rear);
          if(rear == -1){
          front++;
          }
          rear = temp;        
     	  break;
    case 2: 
 	  front=dequeue(queue,front,rear);
          if(front == -1){
           rear = -1;
          }
     	  break;
   case 3:
          display(queue,front,rear);                 
     	  break;
   case 4:
          peek(queue,front);
          break;
     case 5:
         break;
  }  // end of switch 
 } while(ch<5);   //End of while
return 0;   
} //end of main


int enqueue(int queue[],int front,int rear){
   if((rear+1)%Max == front)
     printf("queue is full");
   else{
     rear=(rear+1)%Max;
     printf("\nEnter the element you want to be inserted :");
     scanf("\n%d",&queue[rear]);
    } 
  return rear;
}

int dequeue(int queue[],int front,int rear){
   if(front == -1)
       printf("\nqueue is empty");
   else if(front==rear){
       printf("\ndequeued element is %d",queue[front]);
       front = -1;
     }
   else{
      printf("\ndequeued element is %d",queue[front]); 
      front=(front+1)%Max;
    } 
  return front;
}

void display(int queue[],int front,int rear){
   int temp;
   if(front == -1)
       printf("\nqueue is empty");
   else{
       temp=front;
       while(temp != rear){    
          printf("\n%d",queue[temp]);
          temp = (temp+1)%Max;
        }
       printf("\n%d",queue[temp]);
     }
}

void peek(int queue[],int front){
    printf("\njust checking");
   if(front == -1)
       printf("\nqueue is empty");
   else
       printf("\nElement at the front is %d",queue[front]);
}

