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
 	nodetype *last=NULL,*front=NULL;
    char choice;
    int opt;

 	do
 	{
 	  printf("\nEnter your choice \n1 Push \n2 Pop \n3 Display \n4 Exit \n");
	   scanf("%d",&opt);

	  switch(opt){
	   case 1:
	      last = push(last);
	      break;
	  case 2 :
	      if(last!=NULL)
	        front=last->next;
	      front= pop(front);
          if(front!=NULL)
	         last->next=front;
	      break;
	   case 3:
	       display(last);
		   break;
	   case 4 :
	       break;
     }

    }while(opt<4);

   return 0;
 }

 nodetype* push(nodetype *last){
 	int num;
 	nodetype *p;
 	printf("\nEnter the element to be pushed :");
 	scanf("%d",&num);
 	p=(nodetype*)malloc(sizeof(nodetype));
    	if(p!=NULL){
              if(last==NULL){
    		          p->data=num;
    		          p->next=p;
    		          last=p;
                }
                else{
                    p->data=num;
                    p->next=last->next;
                    last->next=p;
                }
		}
		else{
		   printf("\nMemory not allocated");
 	}
 	return last;
 }

  nodetype* pop(nodetype *front){
 	nodetype *temp;
 		if(front!=NULL){
 			temp=front;
 			printf("\nPopped element is %d",front->data);
    		front=front->next;
    		free(temp);
		}
		else{
		   printf("\nstack is empty");
 	}
 	return front;
 }

 void display(nodetype *last){

 		if(last!=NULL){
                nodetype *front=last->next;
 			do{
                printf("\n%d",front->data);
                front=front->next;
 			}while(front!=last->next);
		}
		else{
		   printf("\nstack is empty");
 	}
 }

