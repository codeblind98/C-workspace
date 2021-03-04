#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node *pvs;
	int data;
	struct node *next;
}nodetype;

nodetype* MergeTwoSortedDoublyLinkedList(nodetype*,nodetype*);
void display(nodetype*);
void createLinkedList(nodetype**,nodetype**);

int main(){
	nodetype *head1=NULL,*head2=NULL,*head3=NULL,*tail1=NULL,*tail2=NULL;
	int opt;
	while(1){
		printf("\nEnter your choice \n 1 Create Link List \n 2 MERGE Link List \n 3 Display \n Press any key to exit\n");
		scanf("%d",&opt);
		if(opt==1){
			createLinkedList(&head1,&tail1);
			printf("----------Displaying first linked list----------\n");
			display(head1);
			createLinkedList(&head2,&tail2);
			printf("----------Displaying second linked list----------\n");
			display(head2);
		}
		else if(opt==2)
			head3=MergeTwoSortedDoublyLinkedList(head1,head2);
		else if(opt==3){
		    printf("----------Displaying New Merged linked list----------\n");
		    display(head3);
	    }
	    else
	    break;
	}
	return 0;
}


void createLinkedList(nodetype **hd,nodetype **tl){
  nodetype *p=NULL;
  int num;
  //char choice;
  while(1){
  printf("\nEnter data to be inserted : ");
  scanf("%d",&num);
  p=(nodetype*)malloc(sizeof(nodetype));
  p->data=num;
  if(*hd==NULL){
  	p->pvs=NULL;
  	*hd=*tl=p;
  }	
  else{
  	p->pvs=(*tl);
  	(*tl)->next=p;
  	*tl=p;
  }
  p->next=NULL;
  printf("\nDo you want to continue Press 1 ");
  scanf("%d",&num);
  if(num!=1)
  break;
 }
}

nodetype* MergeTwoSortedDoublyLinkedList(nodetype *head1,nodetype *head2){
	nodetype *head3=NULL, *tail3=NULL, *p=NULL;
	while((head1!=NULL)&&(head2!=NULL)){
		 p=(nodetype*)malloc(sizeof(nodetype));
         if(head3==NULL){
  	        p->pvs=NULL;
  	        head3=tail3=p;
          }     	
         else{
  	       p->pvs=tail3;
  	       tail3->next=p;
  	       tail3=p;
          }
           p->next=NULL;
           
        if(head1->data<head2->data){
        	p->data=head1->data;
        	head1=head1->next;
		}
		else{
			p->data=head2->data;
        	head2=head2->next;
		}   
		
	 }
	 if(head1==NULL)
	 p->next=head2;
	 else
	 p->next=head1;

return head3;
}

void display(nodetype *front){
	if(front==NULL)
	 printf("\nList is empty\n");
	else{
		while(front!=NULL){
			printf("%d\t",front->data);
			front=front->next;
		}
	}
	
}
