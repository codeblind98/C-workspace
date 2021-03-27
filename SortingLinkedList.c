#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
 }nodetype;

nodetype* createLinkedList();
void sort(nodetype*);
void display(nodetype*);

int main(){
    nodetype *front=NULL;
    front=createLinkedList();
    printf("\n----------Printing original LinkedList-------------");
    display(front);
    sort(front);
    printf("\n----------Printing sorted LinkedList-------------");
    display(front);
    
    
return 0;
}

nodetype* createLinkedList(){
      nodetype *p=NULL,*front=NULL,*rear=NULL;
      int num, choice;
      do{
           printf("\nEnter the value to be inserted :");
           scanf("%d",&num);
    
           p=(nodetype*)malloc(sizeof(nodetype));
           if(p!=NULL)
              p->data=num;
            else
              printf("\nmemory not allocated");
            if(rear==NULL)
               rear=front=p;
            else{
               rear->next=p;
               rear=p;
            }
            rear->next=NULL;
            printf("\nDo you want to continue , press 1 :");
            scanf("%d",&choice);
        } while(choice==1);
    return front;      
   }

 void sort(nodetype* front){
	 int num;
	 nodetype *temp1,*temp2;
	 temp1=front;
	 while(temp1->next!=NULL){
	 	  temp2=front;
	 	  while(temp2->next!=NULL){
	 	  	if((temp2->data) > (temp2->next)->data){
			   num=temp2->data;
			   temp2->data=(temp2->next)->data;
			   (temp2->next)->data=num;
	     	  }
	     	  temp2=temp2->next;
		   }
		   temp1=temp1->next;
	 }
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



