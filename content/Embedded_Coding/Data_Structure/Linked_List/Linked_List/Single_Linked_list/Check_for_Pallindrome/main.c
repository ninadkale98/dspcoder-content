#include "../../util.h"

bool checkPallindrome(struct Linked_List* head ){
    // 1 -> 2 -> 3 -> 2 -> 1
    int len = give_length(head); 
    int arr[len]; 
    struct Linked_List* dummy_head = head; 
    
    for(int i = 0; i < len; i++){
        arr[i] = dummy_head->data; 
        dummy_head = dummy_head->next; 
    }

    dummy_head = head; 

    for(int i = 0; i < len/2 ; i++){
        if(arr[len -1 - i] != dummy_head->data){
            return false; 
        }
        dummy_head= dummy_head->next; 
    }

    return true; 
}

int main(){
    int node_arr[] = {7, 7}; 
    
    struct Linked_List* head =  give_LinkedList(node_arr, sizeof(node_arr)/sizeof(node_arr[0])); 
    print_LinkedList(head); 

    bool isPallindrome = checkPallindrome(head); 

    if (isPallindrome){
        printf("True");
    }
    else{
        printf("False");
    }


    return 0; 
}