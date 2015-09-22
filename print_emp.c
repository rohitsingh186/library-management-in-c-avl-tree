#include "header.h"

void print_emp(node_type* ptr)
{		/* Printing Data of a particular node */
	if(ptr!=NULL)
	{
		printf("Employee Number :-  %d\n",ptr->emp_number);
		printf("Employee Name :-  %s\n",ptr->emp_name);
		printf("Employee Designation :-  %s\n",ptr->emp_dsgn);
		printf("Employee Address :-  %s\n",ptr->emp_add);
		printf("Employee Phone :-  %lu\n",ptr->emp_phone);
		printf("Balance :- %d",ptr->balance);
	}
}
