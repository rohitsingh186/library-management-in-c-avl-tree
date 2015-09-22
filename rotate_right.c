#include "header.h"

node_type* rotate_right(node_type* ptr)
{		/* Rotating Right */
	node_type *tmp;
	tmp=ptr;
	printf("RR");
	if(ptr==NULL || ptr->left==NULL)
	{
		printf("Error occured in right rotation\n");	
	}
	else		/* Error Condition */
    {
		tmp=ptr->left;
		ptr->left=tmp->right;
		if(tmp->right!=NULL)
		{
			(tmp->right)->parent=ptr;
		}
		tmp->right=ptr;	
		ptr->parent=tmp;
	}
	return tmp;
}
