#include "header.h"

int height(tree* trptr)
{
	int ht=-1;
	ht=find_ht(trptr->root);	/* Calling Auxilliary Functions */
	return ht;
}
