#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 void push(nodetype**);
 void pop(nodetype**);
 void display(nodetype*);

 int main(){
 	nodetype *top=NULL;
    char choice;
    int opt;
 	
 	do
 	{
 	  printf("\nEnter your choice \n1 Push \n2 Pop \n3 Display \n Any key to Exit \n Enter your choice : ");
	   scanf("%d",&opt);
	   
	  switch(opt){
	   case 1:
	       push(&top);
	      break;
	   case 2:
	      	pop(&top);
	      	break;
	   case 3:
	       display(top);
		   break;
	   default :
	       break; 
     }
	
    }while(opt<=3&&opt>0);
  
   return 0;
 }
 
 void push(nodetype **tp){
 	int num;
 	nodetype *p;
 	printf("\nEnter the element to be pushed :");
 	scanf("%d",&num);
 	p=(nodetype*)malloc(sizeof(nodetype));
    	if(p!=NULL){
    		p->data=num;
    		p->next=*tp;
    		*tp=p;
		}
		else{
		   printf("\nMemory not allocated");
    	}

 }
 
  void pop(nodetype **tp){
 	nodetype *temp;
 	    
 		if(*tp!=NULL){
 			temp=*tp;
 			printf("\nPopped element is %d",(*tp)->data);
    		*tp=(*tp)->next;
    		free(temp);
		}
		else{
		   printf("\nstack is empty");
 	    }
 }
 
 void display(nodetype *top){ 
 		if(top!=NULL){
 			while(top!=NULL){
 			  printf("\n%d",top->data);
 			  top=top->next;
 		   }
		}
		else{
		   printf("\nstack is empty");
 	}
 }
  
