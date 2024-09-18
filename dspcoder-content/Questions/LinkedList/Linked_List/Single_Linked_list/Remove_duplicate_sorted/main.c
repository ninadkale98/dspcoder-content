#include "../../util.h"

void remove_duplicate(struct Linked_List** head){
    
    struct Linked_List* dummy_head = *head; 
    // 1 -> 2 -> 2 -> 3 -> 4 -> 4
    // if head.data == head.next.data
    // t1 = head.next.next : 3
    // t2 = head.next : 2
    // head.next = t1
    // free(t2)

    struct Linked_List* t1;
    struct Linked_List* t2;

    // if curr == curr.next | remove curr.next
    while(dummy_head->next){
        if(dummy_head->data == dummy_head->next->data){
            t1 = dummy_head->next->next; 
            t2 = dummy_head->next;
            dummy_head->next = t1 ; 
            free(t2); 
        }
        else {
            dummy_head = dummy_head->next; 
        }
    }

}

int main(){
    int node_arr[] = {1, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4}; 

    struct Linked_List* head =  give_LinkedList(node_arr, sizeof(node_arr)/sizeof(node_arr[0])); 
    print_LinkedList(head); 

    remove_duplicate(&head);
    print_LinkedList(head); 

    return 0; 
}