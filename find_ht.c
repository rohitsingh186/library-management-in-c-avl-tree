#include "header.h"

int find_ht(node_type* ptr)
{		/* Auxilliary Function for finding height*/
	int htr,htl,ht=-1;
	if(ptr!=NULL)
	{
		htl=find_ht(ptr->left);
		htr=find_ht(ptr->right);
		if(htl>htr)		/* Height of Left Subtree is greater*/
		{
			ht=htl+1;	
		}
		else		/* Height of Right Subtree is greater*/
		{
			ht=htr+1;	
		}
	}
	return ht;
}
