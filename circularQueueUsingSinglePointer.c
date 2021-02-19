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
	  	  last=pop(last);
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
 	return p;
 }

  nodetype* pop(nodetype *last){
 	nodetype *temp=NULL;
 		if(last!=NULL){
 		      temp=last->next;
 		    if(temp!=last){
 		    	printf("\npopped element is %d",temp->data);
 		    	last->next=temp->next;
 		    	free(temp);
 		    	return last;
			 }
			 else{
			    printf("\npopped element is %d",last->data);
				temp=NULL;
				free(last);
				return temp;	
			 }
		}
		else{
		   printf("\nstack is empty");
 	}
 	
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
