#include "header.h"

int num_records(node_type *ptr)
{		/* Auxilliary Function for Get Num Records */
	int numl=0,numr=0,num=0;
	if(ptr!=NULL)
	{
		numl=num_records(ptr->left);
		numr=num_records(ptr->right);
		num=numl+numr+1;	
	}
	return num;
}

