#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 nodetype* push(nodetype*);
 nodetype* pop(nodetype*);
 void display(nodetype*);

 int main(){
 	nodetype *top=NULL;
    char choice;
    int opt;
 	
 	do
 	{
 	  printf("\nEnter your choice \n1 Push \n2 Pop \n3 Display \n4 Exit \n");
	   scanf("%d",&opt);
	   
	  switch(opt){
	   case 1:
	      top = push(top);
	      break;
	   case 2:
	      top = pop(top);
	      break;
	   case 3:
	       display(top);
		   break;
	   case 4 :
	       break; 
     }
	
    }while(opt<4);
  
   return 0;
 }
 
 nodetype* push(nodetype *top){
 	int num;
 	nodetype *p;
 	printf("\nEnter the element to be pushed :");
 	scanf("%d",&num);
 	p=(nodetype*)malloc(sizeof(nodetype));
    	if(p!=NULL){
    		p->data=num;
    		p->next=top;
    		top=p;
		}
		else{
		   printf("\nMemory not allocated");
 	}
 	return top;
 }
 
  nodetype* pop(nodetype *top){
 	nodetype *temp;
 	    
 		if(top!=NULL){
 			temp=top;
 			printf("\nPopped element is %d",top->data);
    		top=top->next;
    		free(temp);
		}
		else{
		   printf("\nstack is empty");
 	}
 	return top;
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
  
