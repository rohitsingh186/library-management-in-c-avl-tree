#include "header.h"

void range_search(tree* trptr,int num_lo,int num_hi)
{
	node_type *ptr;
	ptr=trptr->root;
	r_search(ptr,num_lo,num_hi);
	if(trptr->root==NULL)		/* Tree is Empty */
	{
		printf("There is no data present in the database\n");	
	}
	return;
}

void r_search(node_type *ptr,int num_lo,int num_hi)
{
	if(ptr!=NULL)
	{
		if(num_lo<ptr->emp_number)		/* Lower Bound is not reached yet */
		{
			r_search(ptr->left,num_lo,num_hi);	
		}
		if(num_lo<=ptr->emp_number && ptr->emp_number<=num_hi)		/* Within Range */
		{
			print_emp(ptr);	
		}
		if(ptr->emp_number<num_hi)		/* Upper Bound is not reached yet */
		{
			r_search(ptr->right,num_lo,num_hi);	
		}
	}
	return;
}
