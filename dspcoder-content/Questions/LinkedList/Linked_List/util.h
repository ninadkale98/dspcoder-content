#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "util.c"

extern struct Linked_List* give_LinkedList(int arr[], int n) ; 
extern void print_LinkedList(struct Linked_List* head); 
extern void insert_node(struct Linked_List* head, int node_indx , int new_node_val);
extern void  delete_node(struct Linked_List** head, int node_indx );
extern struct Linked_List* search_node(struct Linked_List* head, int node_val);
extern int give_length(struct Linked_List* head);
extern void reverse_LinkedList(struct Linked_List** ptr_head);
