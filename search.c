#include "header.h"

node_type* search(tree* trptr,int number)
{
	node_type *prev,*ptr;
	int found=0;
	prev=NULL;
	ptr=trptr->root;
	if(trptr->root==NULL)		/* Tree is Empty */
	{
		printf("Given Employee number doesn't exist.\n");
	}
	else
	{
		while(found==0 && ptr!=NULL)
		{
			if(number==ptr->emp_number)		/* Data Found */
			{
				print_emp(ptr);	
				found=1;
			}
			else if(number>ptr->emp_number)		/* Data may be present in right subtree */
			{
				printf("r");
				prev=ptr;
				ptr=ptr->right;	
			}
			else	/* Data may be present in left subtree */
			{
				printf("l");
				prev=ptr;
				ptr=ptr->left;	
			}
		}
		if(ptr==NULL)
		{
			ptr=prev;	
		}
	}
	return ptr;
}
