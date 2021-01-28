 #include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
}nodetype;

int main(){
	nodetype *left=NULL,*right=NULL, *p=NULL;
	int n ,ch;
	do
	{
	    printf("\nEnter the data you want to enter in the node :");
	    scanf("%d",&n);
	    p=(nodetype*)malloc(sizeof(nodetype));
	    p->data=n;
	    if(left==NULL){
	    	left=right=p;
		}
		else{
			right->next=p;
			right=p;
		}
		printf(" Press 1 if you want to continue\n");
		scanf("%d",&ch);
		
    }while(ch==1);
    right->next=NULL;
   // printf("\ntest");
    while(left!=NULL){
       printf("\n%d",left->data);
	   left=left->next;	
	}
	return 0;
}

