#include "../../util.h"

struct Linked_List* merger_sorted(struct Linked_List* head1 , struct Linked_List* head2){
    // 1 -> 3 -> 4
    // 2 -> 3 -> 4
    // check min head1, head2 and append it to head till one of them is null. later apped not null

    struct Linked_List* head ; 
    struct Linked_List* start ;

    int has_start_assigned = 0; 
    

    while(head1 && head2  ){
        if(head1->data >= head2->data){
            head = (struct Linked_List* ) malloc(sizeof(struct Linked_List ));
            head->data = head1->data; 
            if(! has_start_assigned){
                has_start_assigned = 1; 
                start = head; 
            }
            head = head->next;
            head1 = head1->next; 
        }
        else{
            head = (struct Linked_List* ) malloc(sizeof(struct Linked_List));
            if(! has_start_assigned){
                has_start_assigned = 1; 
                start = head; 
            }

            head->data = head2->data; 
            head = head->next;
            head2 = head2->next; 
        }
    }
    if(head1 == NULL && head2 != NULL){
        head = head2; 
    }
    if(head2 == NULL && head1 != NULL){
        head = head1;
    }

    return start; 

}


int main(){
    int node_1[] = {1, 3, 5, 7, 9}; 
    int node_2[] = {1, 2, 4, 5, 5, 7, 8}; 


    struct Linked_List* head1 =  give_LinkedList(node_1, sizeof(node_1)/sizeof(node_1[0])); 
    struct Linked_List* head2 =  give_LinkedList(node_2, sizeof(node_2)/sizeof(node_2[0])); 
    
    print_LinkedList(head1); 
    print_LinkedList(head2);

    struct Linked_List* merge_head = merger_sorted(head1 , head2); 
    
    print_LinkedList(merge_head); 
    

}




// 1 - 2 
//               - 5 - 6
// 4 - 5 - 6 - 6