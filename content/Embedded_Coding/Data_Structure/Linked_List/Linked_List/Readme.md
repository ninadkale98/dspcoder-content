# Linked List

This is a linear data structure where elements are stored in non contagious memory locations. Each node stores a value and pointer to next node. 

'''c

struct Linked_List{
    int data; 
    struct Linked_List* next; 
};

int main(){
    struct Linked_List* head = (struct Linked_List*)malloc(sizeof(struct Linked_List)); 
    head->data = 10; 
    head->next = NULL; // This will point to next element 

}

'''

## Advantage of Linked List Data structure 

- Dynamic Data Structure : Size can be changed in runtime
- Ease of inserting/deleting of node
- Efficient memory usage : Only required amount of meomery is used 

## Disadvantage of Linked List 

- Cant directly access elements, need to traverse 
- Extra memory is needed to store pointer 


## How to explain it to noob

Think of Lego block where each block is connected to next using thread. Now if you store lets a all blocks in one box, you can still will be able to trac next block(Nide) using thread(pointer to next block). Hence u dont necesaarisly need contagious structure as thread can help me navigate

## Types of Linked List

- Single Linked List : contains pointer only to next node in sequence 
- Double Linked List : contains pointer to next and prev node in sequence 
- Circular Linked List : Last node points to first node creating a loop. It can be singly linked or doubly linked

