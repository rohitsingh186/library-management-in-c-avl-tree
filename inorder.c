#include "header.h"

void inorder(node_type *ptr)
{		/* Inorder Traversal */
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		print_emp(ptr);
		inorder(ptr->right);
	}
}
