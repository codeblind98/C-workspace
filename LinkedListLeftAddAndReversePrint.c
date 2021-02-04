#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;
 
 void display(nodetype*);

 int main(){
   nodetype *left=NULL,*p=NULL;
   int n,ch;
   while(1){
      printf("\nEnter element :");
      scanf("%d",&n);
      p=(nodetype*)malloc(sizeof(nodetype));
      p->data=n;
      p->next=left;
      left=p;
      printf("\nEnter 1 to continue and any other key to exit:");
      scanf("%d",&ch);
      if(ch!=1)
        break;
	}
	display(left);
   return 0;
 }
 
 void display(nodetype *left){
 	 if(left!=NULL){
 	   //	left=left->next;
 	 	display(left->next);
        printf("%d\n",left->data);
   }
 }
 
