#include "header.h"

node_type* rotate_left(node_type* ptr)
{		/* Rotating Left */
	node_type *tmp;
	tmp=ptr;
	printf("RL");
	if(ptr==NULL || ptr->right==NULL)		/* Error Condition */
	{
		printf("Error occured in left rotation\n");	
	}
	else
    {
		tmp=ptr->right;
		ptr->right=tmp->left;
		if(tmp->left!=NULL)
		{
			(tmp->left)->parent=ptr;
		}
		tmp->left=ptr;
		ptr->parent=tmp;	
	}
	return tmp;
}
