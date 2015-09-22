#include "header.h"

main()
{
	/*Declarations*/
	tree tr;
	status_code SC=SUCCESS;
	int ht,num,option,contnue,num_lo=0,num_hi=0;
	char dumbo[2];
	int number;
	char name[NAME_LEN];
	char dsgn[DSGN_LEN];
	char add[ADD_LEN];
	long int phone;
	initialize(&tr);
	/*Declarations End*/
	do
	{
		/* Asking for different operations */
		puts("ENTER the option as per the operation you want to do. ENTER :-\n");
		puts("1- insert/update\n2- delete\n3- Search\n4- getNumRecords\n5- Height\n6- Range Search\n7- Print Database\n\n");
		printf("Your Choice is:- ");
		scanf("%d",&option);
		printf("\n\n");
		switch (option)
		{
			/* INSERT/UPDATE */
			case 1: {
						    printf("***********INSERT**********\n\n");
						    /* Data Entering Start */
						    printf("Enter Employee's Number :-\t");
							scanf("%d",&number);
							printf("Enter Employee Name :-\t");
							gets(dumbo);
							gets(name);
							remove_space_make_uppercase(name);
							printf("Enter Employee's Designation :-\t");
							gets(dsgn);
							remove_space_make_uppercase(dsgn);
							printf("Enter Employee's Address :-\t");
							gets(add);
							remove_space_make_uppercase(add);
							printf("Enter Employee's Phone Number :-\t");
							scanf("%lu",&phone);
							/* Data Entering End */
							/* Inserting/Updating Data */
							SC=insert_emp(&tr,number,name,dsgn,add,phone);
							if(SC==SUCCESS)
							{
								puts("\n**********Data inserted**********\n");	
							}
							else
							{
								puts("\n**********Data insertion failed**********\n");	
							}
					  		break;
				     }
			/*Search*/
			case 3:  {
							printf("Enter Employee's Number :-\t");
							scanf("%d",&number);
							search(&tr,number);
							break;
					 }
			/* Get Num Records */
			case 4:  {
							num=get_num_records(&tr);
							printf("Number of records present in the tree is %d",num);
							break;
			         }
			/* Height of the tree */
			case 5:  {
							ht=height(&tr);
							printf("Height of the tree is %d",ht);
							break;
			         }
			/* Range Search */
			case 6:  {
							printf("\nEnter lower bound :- \t");
							scanf("%d",&num_lo);
							printf("\nEnter upper bound :- \t");
							scanf("%d",&num_hi);
							if(num_lo<num_hi)
							{
								range_search(&tr,num_lo,num_hi);
							}
							else
							{
								printf("Please enter valid bounds.\n");	
							}
							break;
					 }
			/* Print Database */
			case 7:  {
							print_database(&tr);
							break;
					 }
			/* Default */
			default: {
							break;
					 }
		}
		/* Asking for CHOICE to Continue */
		puts("\n\nIf you want to continue... ? Enter 1 if YES or 0 if NO\n");
		printf("Your Choice is:- ");
		scanf("%d",&contnue);
		printf("\n\n");
	}while(contnue==1);
	getch();
}
