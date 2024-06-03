/*
    Given Linked List find middle elem
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 

    Solution: 
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
        s    f
        
*/
#include "../../util.h"
#include <time.h>

int give_middle_elem(struct Linked_List* head){
    // 1 -> 2 -> 3 -> 4
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Linked_List* slow = head; 
    struct Linked_List* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next; 
        slow = slow->next; 
    }
    
    return slow->data; 
    
}

int main(int argc, char *argv[]){

    clock_t start, end;
    double cpu_time_used;

    if (argc <= 1 ){
        printf("Please pass array values in argument"); 
    }

    int node_arr[argc - 2]; 
    for(int i = 0; i < (argc -2) ; i++){
        node_arr[i] = atoi(argv[i + 1]); 
    }

    int ans = atoi( argv[argc-1] );

    struct Linked_List* head =  give_LinkedList(node_arr, sizeof(node_arr)/sizeof(node_arr[0])); 
    // print_LinkedList(head); 

    start = clock();
    int middel_elem = give_middle_elem(head); 
    end = clock();

    cpu_time_used = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC; 
    
    if(ans == middel_elem){
        printf("Test Case Passed. "); 
    }
    else{
        printf("Test Case Failed. "); 
    }

    printf("CPU time used: %f milliseconds\n", cpu_time_used);


    // printf("Middle element is %d", middel_elem); 
}