#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node* NODE;

void setFree(NODE root)
{
	if(root!=NULL)
		free(root);
	else{
		setFree(root->left);
		setFree(root->right);
	}
}

//creating a new node

NODE NewNode(int element) { 
	struct node temp; 
	temp.data = element;
	temp.left=NULL;
	temp.right=NULL;
	return &temp;
}

//calculate the max depth of the tree
int maxDepth(NODE node)
{
	int lDepth,rDepth;
	if(node == NULL) return 0;
	else
	{
		lDepth = maxDepth(node->left);
		rDepth = maxDepth(node->right);
	}
	return lDepth>rDepth ? lDepth+1:rDepth+1;
}

void insertNode(NODE root,NODE new_node)
{
	if(root->data > new_node->data ) 
		if(root->right==NULL)
			root->right = new_node;
		else insertNode(root->right,new_node);
	else
		if(root->left==NULL)
			root->left=new_node;
		else insertNode(root->left,new_node);
		
}
void postorder(NODE root)
{
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}

int main()
{	
	NODE root=NULL;
	NODE new_node = NULL;
	int element;
	int Elements[]={3,5,12,10,23,2,9,1,0,3,8,0};
	int i=0;
	while(i<10){
	printf("Enter the element to insert \t");
//	scanf("%d",&element);
	element = Elements[i];
	printf("%d\n",element);
	if(root == NULL)
	{
		root = (NewNode(element));
	}
	else
	{
		new_node=NewNode(element);
		insertNode(root,new_node);

	}
	i++;
	}
	postorder(root);
	return 0;
}

									

