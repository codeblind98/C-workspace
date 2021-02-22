#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int processNumber;
	 int data;
     struct node *next;
 }nodetype;

 nodetype* createProcessTable(nodetype*);
// nodetype* startProcess(nodetype*);
 void display(nodetype*);

 int main(){
 	nodetype *last=NULL;
    int opt;

 	do
 	{
 	  printf("\nEnter your choice \n1 CREATE PROCESS \n2 RUN PROCESS \n3 DISPLAY PROCESS TABLE \n4 Exit \n");
	   scanf("%d",&opt);

	  switch(opt){
	   case 1:
	      last = createProcessTable(last);
	      break;
	 /* case 2 :
	  	  last = startProcess(last);
	      break; */S
	   case 3:
	       display(last);
		   break;
	   case 4 :
	       break;
     }

    }while(opt<4);

   return 0;
 }

 nodetype* createProcessTable(nodetype *last){
 	int time,totalProcess,i;
 	nodetype *p;
 	printf("\nEnter total number of processes : ");
 	scanf("%d",&totalProcess);
 	for(i=0;i<totalProcess;i++){
 	      printf("\nEnter time taken by PROCESS %d  to finish  :",i+1);
 	      scanf("%d",&time);
 	      p=(nodetype*)malloc(sizeof(nodetype));
    	           if(p!=NULL){
    	           	    p->processNumber=i+1;
    	           	    p->data=time;
              			if(last==NULL){
    		          		last=p;
    		          		last->next=p;
                		}
                		else{
                    		p->next=last->next;
                    		last->next=p;
                    		last=p;
                		}
					}
					else
		   printf("\nMemory not allocated");
	}
	return last;
 }

 /* nodetype* pop(nodetype *last){
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
 	
 }*/

 void display(nodetype *last){

 		if(last!=NULL){
                nodetype *front=last->next;
 			do{
                printf("\np%d : %d",front->processNumber,front->data);
                front=front->next;
 			}while(front!=last->next);
		}
		else{
		   printf("\nstack is empty");
 	}
 }
