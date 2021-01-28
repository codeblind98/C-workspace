#include<stdlib.h>
#include<stdio.h>

typedef struct node {
	int data;
	struct node *next;
}nodetype;

int main(){
	nodetype p1,p2,p3,p4,*ptr=NULL;
	p1.data=10;
	p2.data=20;
	p3.data=30;
	p4.data=40;
	
	p1.next=&p2;
    p2.next=&p3;
	p3.next=&p4;
    p4.next=NULL;
    ptr=&p1;
    while(ptr!=NULL){
    	printf("\n%d",ptr->data);
    	ptr=ptr->next;
	}
	return 0;
}

