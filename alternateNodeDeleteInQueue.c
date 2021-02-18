#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
 }nodetype;

nodetype* insert(nodetype*);
nodetype* alternateDel(nodetype*);
void display(nodetype*);

int main(){
    nodetype *front=NULL,*rear=NULL;
    int ch;
    do{
       printf("\n1 Insert \n2 Delete \n3 Display \n4 Exit \n Enter your choice :");
       scanf("%d",&ch);
       switch(ch){
          case 1:
             rear = insert(rear);
             if(front==NULL)
              front=rear;
             break;
          case 2:
             front = alternateDel(front);
             if(front==NULL)
              rear=front;
             break;
          case 3:
             display(front);
             break;
          case 4:
             break;
        }

    }while(ch<=3&&ch>0);
return 0;
}

nodetype* insert(nodetype *rear){
      nodetype *p=NULL;
      int num;
      printf("\nEnter the value to be inserted :");
      scanf("%d",&num);

      p=(nodetype*)malloc(sizeof(nodetype));
      if(p!=NULL)
         p->data=num;
      else
         printf("\nmemory not allocated");
      if(rear==NULL)
         rear=p;
      else{
          rear->next=p;
          rear=p;
        }
      rear->next=NULL;

  return rear;
 }

nodetype* alternateDel(nodetype *front){
     int count=1;
     nodetype *temp=NULL,*frontprev=NULL,*frontholder=front;
     while(front!=NULL){
          if(count%2!=0){
            frontprev=front;
            front=front->next;
            count++;
            continue;
          }
          else{
            temp=front;
            frontprev->next=front->next;
            front=front->next;
            count++;
            free(temp);
          }
     }
     return frontholder;
 }


void display(nodetype *front){
	 if(front!=NULL){
           while(front!=NULL){
              printf("\n%d",front->data);
              front=front->next;
            }
	}
	else
	printf("\nqueue is empty");
 }




