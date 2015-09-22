#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 32
#define ADD_LEN 64
#define DSGN_LEN 16

typedef enum status{FAILURE,SUCCESS}status_code;

/* Defining Data Types */

typedef struct node
{
	int emp_number;
	char emp_name[NAME_LEN];
	char emp_dsgn[DSGN_LEN];
	char emp_add[ADD_LEN];
	long int emp_phone;
	struct node *left;
	struct node *right;
	struct node *parent;
	int balance;
}node_type;

typedef struct
{
	node_type *root;
}tree;

/*Main Funcions*/

status_code insert_emp(tree*,int,char [],char [],char [],long int);

status_code delete_emp(tree*,int);

node_type* search(tree*,int);

int get_num_records(tree*);

int height(tree*);

void range_search(tree*,int,int);

void print_database(tree*);

/*Auxilliary Functions*/

node_type* make_node(int,char [],char [],char [],long int);

void print_emp(node_type*);

void height_balance(tree*,node_type*);

void remove_space_make_uppercase(char[]);

void initialize(tree*);

void inorder(node_type*);

int find_ht(node_type*);

int num_records(node_type*);

node_type* rotate_left(node_type*);

node_type* rotate_right(node_type*);

void r_search(node_type*,int,int);

#endif
