#include "header.h"

void height_balance(tree* trptr,node_type* ptr)
{
	node_type *prev,*aptr;
	while(ptr!=trptr->root)
	{
		prev=ptr->parent;
		if(prev->balance==2)
		{
			if(ptr->balance==1)
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
					prev=aptr;	
					printf("r");
				}
				else
				{
					printf("p3");
					aptr=(prev)->parent;
					aptr->right=rotate_left(prev);
					(aptr->right)->parent=aptr;	
					prev=aptr;
					printf("r");
				}		
			}	
			else if(ptr->balance==-1)
			{
				ptr->balance=0;
				(prev)->balance=0;
				printf("p3.2");
				prev->right=rotate_right(ptr);
				(prev->right)->parent=prev;
				printf("r3.2");
				if(prev==trptr->root)
				{
					printf("p10");
					trptr->root=rotate_left(prev);	
					(trptr->root)->parent=NULL;
					ptr=trptr->root;
					printf("r");
				}
				else if((prev->parent)->left==prev)
				{
					printf("p11");
					aptr=(prev)->parent;
					aptr->left=rotate_left(prev);
					(aptr->left)->parent=aptr;
					ptr=ptr->parent;
					printf("r");		
				}
				else
				{
					printf("p12");
					aptr=(prev)->parent;
					aptr->right=rotate_left(prev);	
					(aptr->right)->parent=aptr;
					ptr=ptr->parent;
					printf("r");
				}	
			}	
		}	
		else if(prev->balance==-2)
		{
			if(ptr->balance==1)
			{
					
			}	
			else if(ptr->balance==-1)
			{
					
			}	
		}
	}
}
