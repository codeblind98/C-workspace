#include<stdio.h>
#include<stdlib.h>

typedef struct node{
     int data;
     struct node *next;
 }nodetype;

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
      printf("\nEnter 1 to continue :");
      scanf("%d",&ch);
      if(ch!=1)
        break;
   }
   while(left!=NULL){
     printf("%d\n",left->data);
     left=left->next;
   }
   return 0;
 }
