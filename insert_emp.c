#include "header.h"

status_code insert_emp(tree* trptr,int number,char name[],char dsgn[],char add[],long int phone)
{
	node_type *nptr,*ptr,*hptr;
	status_code SC=SUCCESS;
	int inc=1;
	ptr=NULL;
	nptr=NULL;
	/* Tree is empty initially */
	if(trptr->root==NULL)
	{
		printf("k");
		nptr=make_node(number,name,dsgn,add,phone);
		if(nptr==NULL)
		{
			SC=FAILURE;	
		}
		else
		{
			trptr->root=nptr;
		}	
	}
	else		/* Tree is not empty initially */
	{
		printf("b");
		ptr=search(trptr,number);
		printf("s %d",ptr->emp_number);
		if(ptr->emp_number==number)		/*UPDATE*/
		{
			printf("1");
			strcpy(ptr->emp_name,name);
			strcpy(ptr->emp_dsgn,dsgn);
			strcpy(ptr->emp_add,add);
			ptr->emp_phone=phone;	
		}
		else if(ptr->emp_number<number)		/*ADD AS RIGHT CHILD*/
		{
			printf("2");
			nptr=make_node(number,name,dsgn,add,phone);
			if(nptr==NULL)
			{
				SC=FAILURE;	
			}
			else
			{
				printf("2.1");
				hptr=ptr;
				ptr->right=nptr;
				nptr->parent=ptr;
				printf("t");
				ptr->balance=(ptr->balance)+1;		/* Manipulating Balance */
				if(ptr->balance==0)
				{
					printf("2.1.1");
					inc=0;	
				}
				while(inc==1 && ptr!=(trptr->root))
				{
					printf("2.1.2");
					if((ptr->parent)->left==ptr)
					{
						printf("2.1.2.1");
						(ptr->parent)->balance=((ptr->parent)->balance)-1;
						if((ptr->parent)->balance==0)
						{
							printf("2.1.2.1.1");
							inc=0;	
						}
					}
					else
					{
						printf("2.1.2.2");
						(ptr->parent)->balance=((ptr->parent)->balance)+1;
						if((ptr->parent)->balance==0)
						{
							printf("2.1.2.2.1");
							inc=0;	
						}	
					}
					ptr=ptr->parent;	
				}
				printf("a");
				height_balance(trptr,hptr);		/* Calling Height Balance */
			}		
		}
		else		/*ADD AS LEFT CHILD*/	
		{
			printf("3");
			nptr=make_node(number,name,dsgn,add,phone);
			if(nptr==NULL)
			{
				SC=FAILURE;	
			}
			else
			{
				printf("3.1");
				hptr=ptr;
				ptr->left=nptr;
				nptr->parent=ptr;
				ptr->balance=(ptr->balance)-1;		/* Manipulating Balance */
				if(ptr->balance==0)
				{
					printf("3.1.1");
					inc=0;	
				}
				while(inc==1 && ptr!=(trptr->root))
				{
					printf("3.1.2");
					if((ptr->parent)->left==ptr)
					{
						printf("3.1.2.1");
						(ptr->parent)->balance=((ptr->parent)->balance)-1;
						if((ptr->parent)->balance==0)
						{
							printf("3.1.2.1.1");
							inc=0;	
						}
					}
					else if((ptr->parent)->right==ptr)
					{
						printf("3.1.2.2");
						(ptr->parent)->balance=((ptr->parent)->balance)+1;
						if((ptr->parent)->balance==0)
						{
							printf("3.1.2.2.1");
							inc=0;	
						}	
					}
					printf("3.1.3");
					ptr=ptr->parent;	
				}
				printf("B");
				height_balance(trptr,hptr);		/* Calling Height Balance */
			}				
		}
	}
	return SC;
}
