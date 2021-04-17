#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int info;
	struct tree *right;
	struct tree *left;
}treetype;

treetype* create(int);
void insert(treetype*,treetype*);
void preorder(treetype*);
void inorder(treetype*);
void postorder(treetype*);
void count_total(treetype*,int*);
void total_leaf_node(treetype*,int*);
void only_left(treetype*,int*);
void only_right(treetype*,int*);
void min_max(treetype*,int*,int*);




int main()
{
	int num;
	treetype *root = NULL, *temp = NULL;
	int ch = 1;
	int n = 0,min,max;
	while(ch != 0)
	{
		printf("Enter 1 for insert \n 2 for Preorder \n 3 for Inorder \n 4 for postorder \n 5 for count \n 6 for Total Leaf \n 7 for Left node in tree \n 8 for Right node in tree \n 9 for Min And Max in tree \n 10 for node who has only left child in tree \n 11 for node who has only right child in tree-> ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter number to insert : ");
				scanf("%d",&num);
	
				temp = create(num);
				if (root == NULL)
					root = temp;
				else
					insert(root,temp);
				
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				n = 0;
				count_total(root,&n);
				printf("Total Number : %d\n",n);
				break;
			case 6:
				n = 0;
				total_leaf_node(root,&n);
				printf("Total Leaf Node : %d\n",n);
				break;
			case 7:
				n = 0;
				count_total(root->left,&n);
				printf("Total Left Node in tree : %d\n",n);
				break;
			
			case 8:
				n = 0;
				count_total(root->right,&n);
				printf("Total Right Node in tree : %d\n",n);
				break;
			case 9:
				min = root->info;
				max = root->info;
				min_max(root,&max,&min);
				printf("Max : %d\t Min : %d\n",max,min);
				break;
			case 10:
				n = 0;
				only_left(root,&n);
				printf("Node having Left child only : %d\n",n);
				break;
			case 11:
				n = 0;
				only_right(root,&n);
				printf("Node having Right child only : %d\n",n);
				break;				
		}	
	}
	return 0;
}

treetype* create(int num)
{
	treetype *temp;
	temp = (treetype*)malloc(sizeof(treetype));
	temp->info = num;
	temp->left = temp->right = NULL;
	return temp;
 }
 


void insert(treetype *root,treetype *temp)
{
	if(temp->info < root->info)
	{
		if(root->left == NULL)
			root->left = temp;
		else
			insert(root->left,temp);
	}
	else
	{
		if(root->right == NULL)
			root->right = temp;
		else
			insert(root->right,temp);
	}
}


void preorder(treetype *root)
{
	if (root != NULL)
	{
		printf("%d\t",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treetype *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d\t",root->info);
		inorder(root->right);
	}
}

void postorder(treetype *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->info);
	}
}

void count_total(treetype *root,int *nt)
{
	if(root != NULL)
	{
		(*nt)++;
		printf("%d\t",root->info);
		count_total(root->left,nt);
		count_total(root->right,nt);
	}
}

void total_leaf_node(treetype *root,int *nt)
{
	if(root != NULL)
	{
		if((root->left == NULL) && (root->right == NULL))
			(*nt)++;
		total_leaf_node(root->left,nt);
		total_leaf_node(root->right,nt);
	}
}


void only_left(treetype *root,int *nt)			
{
	if(root != NULL)
	{
		if( (root->left != NULL) && (root->right == NULL) )
		{
			(*nt)++;
			printf("%d\t",root->info);
		}
		only_left(root->left,nt);
		only_left(root->right,nt);
	}
}


void only_right(treetype *root,int *nt)			
{
	if(root != NULL)
	{
		if( (root->right != NULL) && (root->left == NULL) )
		{
			(*nt)++;
			printf("%d\t",root->info);
		
		}
		only_right(root->left,nt);
		only_right(root->right,nt);
	}
}

void min_max(treetype *root,int *max,int *min)
{
	if(root != NULL)
	{
		if( (root->info) < (*min))
			(*min) = root->info;
		if( (root->info) > (*max))
			(*max) = root->info;
		min_max(root->left,max,min);
		min_max(root->right,max,min);
	}
}

