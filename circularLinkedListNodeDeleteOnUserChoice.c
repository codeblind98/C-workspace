#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}nodetype;

void insert(nodetype**,nodetype**);
void del(nodetype**,nodetype**);
void display(nodetype*);

int main(){
	nodetype *head=NULL , *tail=NULL;
	int opt;
	while(1){
	printf("\nEnter your choice \n 1 ADD NODE \n 2 DELETE NODE \n 3 DISPLAY \n PRESS Any key to exit\n");
	scanf("%d",&opt);
	if(opt==1)
	  insert(&head,&tail);
	else if(opt==2)
	  del(&head,&tail);
	else if(opt==3)
	  display(head);
	else
	  break;
  }
	return 0;
}

void insert(nodetype **fr,nodetype **rr){
	nodetype *p=NULL;
	int num;
	printf("\nEnter number to be inserted : ");
	scanf("%d",&num);
	p=(nodetype*)malloc(sizeof(nodetype));
	p->data=num;
	if(*rr==NULL)
	    *rr=*fr=p;
	else{
		(*rr)->next=p;
		*rr=p;
	}
	 p->next=*fr;
}

void del(nodetype **fr,nodetype **rr){
	nodetype *pvs,*current,*temp;
	int key;
	printf("\nEnter the key : ");
	scanf("%d",&key);
	pvs=current=*fr;
	do{
		if(current->data==key){
			  if(current==*fr){
			  	*fr=(*fr)->next;
			  	temp=current;
			  	(*rr)->next=*fr;
			  }
			  else if(current==*rr){
			  	temp=*rr;
			  	pvs->next=*fr;
			  	*rr=pvs;
			  }
			  else{
			  	pvs->next=current->next;
			  	temp=current;
			   }
			free(temp);
			break;   
		}
		else{
			pvs=current;
			current=current->next;
		}
	}while(current!=(*fr));
}

void display(nodetype *front){
	nodetype *temp=NULL;
	
	if(front==NULL){
		printf("\nList is empty");
	 }
	 else{
	 	temp=front;
	 do{
	 	printf("%d\t",temp->data);
	 	temp=temp->next;
	  }while(temp!=front);
    }
}

