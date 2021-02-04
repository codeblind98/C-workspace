#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}nodetype;


nodetype* insert(nodetype*);
void display(nodetype*);
void split(nodetype*);

int main(){
   nodetype *front=NULL,*rear=NULL;
   int choice;
   do{
      printf("\n1 Insert \n2 Split \n3 Display  \n4 Exit \nEnter your choice :");
      scanf("%d",&choice);
      switch(choice){
        case 1:
             rear=insert(rear);
             if(front==NULL)
                front=rear;
             break;
        case 2:
             split(front);
             break;
        case 3:
            display(front);
            break;
        default:
            break;
         }
   }while(choice<=3&&choice>0);
   return 0;
}

nodetype* insert(nodetype *rear){
  nodetype *p;
  int num;
  printf("\nEnter value to be inserted :");
  scanf("%d",&num);
  p=(nodetype*)malloc(sizeof(nodetype));
  if(p!=NULL)
     p->data=num;
  else
     printf("\nMemory not allocated");
  if(rear==NULL)
    rear=p;
  else{
    rear->next=p;
    rear=p;
  }
  rear->next=NULL;
  return rear;
}

void split(nodetype *orig_front){
  nodetype *newfront=NULL,*temp=NULL;
  int num;
  printf("\nEnter value at which split happen :");
  scanf("%d",&num);
  temp=orig_front;
  while(1){
    if(temp->data==num){
        newfront=temp->next;
        temp->next=NULL;
        break;
    }
    else
        temp=temp->next;
  }

    printf("\nFirst half of the linked list ------------------------------");
    display(orig_front);
    printf("\nSecond half of the linked list -----------------------------");
    display(newfront);
  }



void display(nodetype *front){
 if(front!=NULL){
    while(front!=NULL){
        printf("\n%d",front->data);
        front=front->next;
    }
 }
 else
    printf("\nEmpty Link List");

}


