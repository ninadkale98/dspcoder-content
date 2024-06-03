#include <stdio.h>
#include <stdlib.h>

struct Linked_List{
    int data; 
    struct Linked_List* next; 
} ; 

struct Linked_List* give_LinkedList(int arr[], int n){
    
    struct Linked_List* head = (struct Linked_List* ) malloc(sizeof(struct Linked_List));

    if(n == 0){
        return head; 
    }

    struct Linked_List* dummy_head = head; 
    
    for(int i = 0; i < n ; i++){
        dummy_head->data = arr[i]; 
        if (i != n-1){
            dummy_head->next = (struct Linked_List* ) malloc(sizeof(struct Linked_List));
            dummy_head = dummy_head->next; 
        }
        
    }

    return head; 

}

void print_LinkedList(struct Linked_List* head){

    if(head == NULL){
        printf("Head is NULL"); 
    }

    while(head ){
        printf("%d ", head->data); 
        if(head->next){    
            printf("-> "); 
        }
        head = head->next;
    }
    printf("\n"); 
}

void insert_node(struct Linked_List* head, int node_indx , int new_node_val){
    // 1 -> 2 -> 3 -> 4 -> 5 : lets say indx = 3 // insert after 4
    for(int i = 0 ; i < node_indx ; i ++){
        head = head->next; 
    }

    struct Linked_List* newNode = (struct Linked_List* ) malloc(sizeof(struct Linked_List)); 
    newNode->data = new_node_val; 

    struct Linked_List* temp = head->next; 
    head->next = newNode; // .. 4 -> newNode 
    newNode->next = temp; 
}

void  delete_node(struct Linked_List** head, int node_indx ){ 
    // 1 -> 2 -> 3 -> 4 -> 5 // indx = 3 delete 4th node

    if(node_indx == 0){
        struct Linked_List* tbddel = *head; // 1
        *head = (*head)->next; //2

        free(tbddel); 
    }
    else{

        struct Linked_List* dummy_head = *head; 

        for(int i = 0 ; i < node_indx - 1; i ++){
            dummy_head = dummy_head->next; 
        } // head points to 3 now

        struct Linked_List* temp = dummy_head->next->next; 
        struct Linked_List* tbddel = dummy_head->next; 

        // 3 -> 5
        dummy_head->next = temp; 

        // free 4
        free(tbddel); 
    }

    // return head; 

    
    
}

struct Linked_List* search_node(struct Linked_List* head, int node_val){

    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    int node_indx = 0; 

    while(head){
        if(head->data == node_val){
            printf("Node found at %d index \n", node_indx); 
            return head; 
        }
        else{
            head = head->next; 
        }
        node_indx++ ; 
    }

    printf("Node with val %d not found \n", node_val);
    return NULL; 
}

int give_length(struct Linked_List* head){
    if(head){
        return 1 + give_length(head->next); 
    }
    else{
        return 0; 
    }
}

void reverse_LinkedList(struct Linked_List** ptr_head){
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // steps -: prev = NULL, next = 1->next,  1 -> prev(NULL) | prev = 1
    struct Linked_List* prev = NULL;  
    struct Linked_List* next = NULL;  
    struct Linked_List* head = *ptr_head;

    while(head){
        next = head->next; 
        head->next = prev; 

        prev = head; 
        head = next; 

    }

    *ptr_head = prev; 

}