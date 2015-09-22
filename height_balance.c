#include "header.h"

void height_balance(tree* trptr,node_type* ptr)
{
	node_type *prev,*aptr;
	if(ptr!=trptr->root)
	{
		prev=ptr->parent;
		if(prev->balance==2)
		{
			if(ptr->balance==1)		/* Right-Right Bent */
			{
				ptr->balance=0;
				prev->balance=0;
				if(prev==trptr->root)
				{
					printf("p1");
					trptr->root=rotate_left(prev);
					(trptr->root)->parent=NULL;	
					printf("r");
				}
				else if((prev->parent)->left==prev)
				{
					printf("p2");
					aptr=(prev)->parent;
					aptr->left=rotate_left(prev);
					(aptr->left)->parent=aptr;
					ptr=ptr->parent;
					printf("r");
				}
				else
				{
					printf("p3");
					aptr=(prev)->parent;
					aptr->right=rotate_left(prev);
					(aptr->right)->parent=aptr;	
					ptr=ptr->parent;
					printf("r");
				}		
			}	
			else if(ptr->balance==-1)	/* Right-Left Bent */
			{
				ptr->balance=0;
				(ptr->left)->balance=1;
				printf("p4");
				prev->right=rotate_right(ptr);
				(prev->right)->parent=prev;
				ptr=ptr->parent;
				printf("r");
			}	
		}	
		else if(prev->balance==-2)
		{
			if(ptr->balance==-1)		/* Left-Left Balance */
			{
				ptr->balance=0;
				(prev)->balance=0;
				if(prev==trptr->root)
				{
					printf("p5");
					trptr->root=rotate_right(prev);
					(trptr->root)->parent=NULL;	
					printf("r");
				}
				else if(((prev)->parent)->left==prev)
				{
					printf("p6");
					aptr=(prev)->parent;
					aptr->left=rotate_right(prev);
					(aptr->left)->parent=aptr;	
					ptr=ptr->parent;
					printf("r");
				}
				else
				{
					printf("p7");
					aptr=(prev)->parent;
					aptr->right=rotate_right(prev);
					(aptr->right)->parent=aptr;
					ptr=ptr->parent;
					printf("r");	
				}	
			}	
			else if(ptr->balance==1)	/* Left-Right Bent */
			{
				ptr->balance=0;
				(ptr->right)->balance=-1;
				printf("p8");
				prev->left=rotate_left(ptr);
				(prev->left)->parent=prev;
				ptr=ptr->parent;
				printf("r");
				
			}	
		}
		else
		{
			ptr=ptr->parent;	
		}
		height_balance(trptr,ptr);
	}
}
