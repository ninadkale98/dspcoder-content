#include "util.h"


int main() {

    int node_arr[] = {10, 20 , 30, 40, 60 }; 

    struct Linked_List* head = give_LinkedList(node_arr , sizeof(node_arr)/sizeof(node_arr[0])); 
    print_LinkedList(head);

    insert_node(head, 3 , 50); 
    insert_node(head, 3 , 50); 
    print_LinkedList(head);

    delete_node(&head, 4); 
    print_LinkedList(head);
    
    search_node(head, 600); 
    
    int len = give_length(head); 
    printf("length is %d \n", len); 

    reverse_LinkedList(&head); 
    print_LinkedList(head);
    
    return 0;


}

