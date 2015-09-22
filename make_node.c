#include "header.h"

node_type* make_node(int number,char name[],char dsgn[],char add[],long int phone)
{		/* Making new node */
	node_type *nptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	nptr->emp_number=number;
	strcpy(nptr->emp_name,name);
	strcpy(nptr->emp_dsgn,dsgn);
	strcpy(nptr->emp_add,add);
	nptr->emp_phone=phone;
	nptr->balance=0;
	nptr->left=NULL;
	nptr->right=NULL;
	nptr->parent=NULL;
	return nptr;
}
