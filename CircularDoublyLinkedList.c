#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *pvs;
	int data;
	struct node *next;
}nodetype;

void circular(nodetype**,nodetype**);
void display(nodetype*);

int main(){
	nodetype *head=NULL , *tail=NULL;
	int opt;
	while(1){
	printf("\nEnter your choice \n 1 ADD NODE \n 2 DISPLAY \n PRESS Any key to exit\n");
	scanf("%d",&opt);
	if(opt==1)
	  circular(&head,&tail);
	else if(opt==2)
	  display(head);
	else
	  break;
  }
	return 0;
}

void circular(nodetype **hd,nodetype **tl){
	nodetype *p=NULL;
	int num;
	printf("\nEnter number to be inserted : ");
	scanf("%d",&num);
	p=(nodetype*)malloc(sizeof(nodetype));
	p->data=num;
	if(*hd==NULL){
		p->pvs=p;
		p->next=p;
		*hd=*tl=p;
	}
	else{
		p->next=(*tl)->next;
		p->pvs=*tl;
		(*tl)->next=p;
		*tl=p;
	}
	(*hd)->pvs=*tl;
}

void display(nodetype *head){
	nodetype *temp=NULL;
	if(head==NULL){
		printf("\nList is empty");
	 }
	 else{
	 	temp=head;
	 do{
	 	printf("\t%d",temp->data);
	 	temp=temp->next;
	  }while(temp!=head);
    }
}




















