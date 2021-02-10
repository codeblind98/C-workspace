#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   int data;
   struct node *next;
 }nodetype;

void insert(nodetype**,nodetype**);
void dequeue(nodetype**,nodetype**);
void display(nodetype*);

int main(){
    nodetype *front=NULL,*rear=NULL;
    int ch;
    do{
       printf("\n1 Insert \n2 Delete \n3 Display \n4 Exit \n Enter your choice :");
       scanf("%d",&ch);
       switch(ch){
          case 1: 
             insert(&front,&rear);	
             break;
          case 2: 
             dequeue(&front,&rear);
             break;
          case 3: 
             display(front);
             break;
          default : 
             break;
        }
       
    }while(ch<=3&&ch>0);
return 0;
}

void insert(nodetype **fr,nodetype **rr){
      nodetype *p=NULL;
      int num;
      printf("\nEnter the value to be inserted :");
      scanf("%d",&num);
    
      p=(nodetype*)malloc(sizeof(nodetype));
      if(p!=NULL)
         p->data=num;
      else
         printf("\nmemory not allocated");
      if(*rr==NULL)
         *rr=*fr=p;
      else{
          (*rr)->next=p;
          *rr=p;
        }
      (*rr)->next=NULL;
      
 }

void dequeue(nodetype **fr,nodetype **rr){
      nodetype *temp=NULL,*temp1=NULL;
      temp1=*rr;
      if(*fr==NULL)
         printf("\nqueue is empty");
      else{
         temp=*fr;       
         printf("\ndeleted value is %d",temp->data);
         *fr=(*fr)->next;
           if(*fr==NULL)
               free(temp1);
         free(temp);
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

























