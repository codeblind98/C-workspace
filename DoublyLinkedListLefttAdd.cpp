#include<stdio.h>
#include<stdlib.h>

typedef struct node{
   struct node *pvs;
   int data;
   struct node *next;
 }nodetype;

nodetype* insert(nodetype*);
nodetype* del(nodetype*);
void display(nodetype*);

int main(){
    nodetype *head=NULL,*tail=NULL;
    int ch;
    do{
       printf("\n1 Insert \n2 Delete \n3 Display \n4 Exit \n Enter your choice :");
       scanf("%d",&ch);
       switch(ch){
          case 1: 
             head=insert(head);
			 if(tail==NULL)
			  tail=head	;
             break;
          case 2: 
             head=del(head);
             if(head==NULL)
             tail=head;
             break;
          case 3: 
             display(head);
             break;
          default : 
             break;
        }
       
    }while(ch<=3&&ch>0);
return 0;
}

nodetype* insert(nodetype *head){
      nodetype *p=NULL;
      int num;
      printf("\nEnter the value to be inserted :");
      scanf("%d",&num);
    
      p=(nodetype*)malloc(sizeof(nodetype));
      p->data = num;
      if(head==NULL){
      	head=p;
      	p->next=NULL;
	  }
	  else{
	  	head->pvs=p;
	  	p->next=head;
	  	head=p;
	  }
      head->pvs=NULL;
      return head;
 }

nodetype* del(nodetype *head){
      if(head!=NULL){
	  nodetype *temp=NULL;
      temp = head;
      printf("\nDeleted node data is %d",temp->data);
      head=head->next;
      free(temp);
    }
      else
      printf("\nlist is empty");
     return head;
 }


void display(nodetype *head){
	 if(head!=NULL){
           while(head!=NULL){
              printf("\n%d",head->data);
              head=head->next;
            }
	}
	else
	printf("\nqueue is empty");
 }

























