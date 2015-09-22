#include "header.h"

void print_database(tree *trptr)
{
	if(trptr->root!=NULL)
	{
		inorder(trptr->root);		/* Calling for Inorder Traversal */
	}
	else
	{
		printf("There is no data present in the database\n");	
	}
}
