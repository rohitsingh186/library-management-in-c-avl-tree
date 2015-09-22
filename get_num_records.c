#include "header.h"

int get_num_records(tree* trptr)
{
	int num=0;
	if(trptr->root!=NULL)
	{
		num=num_records(trptr->root);	/* Calling Auxilliary Function */
	}
	return num;
}
