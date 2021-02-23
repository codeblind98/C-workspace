#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int processNumber;
	 int data;
     struct node *next;
 }nodetype;

 nodetype* createProcessTable(nodetype*);
 nodetype* startProcess(nodetype*);
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
	   case 2 :
	  	  last = startProcess(last);
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

  nodetype* startProcess(nodetype *last){
 	nodetype *prev=NULL,*temp=NULL,*current=NULL;
 	prev=last; current=last->next;
 	while(1){
 		current->data -=10;
 		if(current->next==current){
 			printf("\nProcess%d is over",current->processNumber);
 			break;
		 }
		 if(current->data<=0){
		 	prev->next=current->next;
		 	printf("\nProcess%d is over",current->processNumber);
		 	temp=current;
		 	current=current->next;
		 	free(temp);
		 	temp=NULL;
		 }
		 prev=current;
		 current=current->next;
	 }
 	
 	return NULL;
 }

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
