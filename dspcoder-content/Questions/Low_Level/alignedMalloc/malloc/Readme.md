# Malloc

## Problem Statement : 

Implement malloc function which will return memory address of memory block which will be assigned to pointer

## Key points to keep in mind for interview 

1. Interviewers are not interested in correct answers, but how you approach this problem
2. Try to cover following points and ask right questions before moving to code implementation 

## How does Malloc and free works 

1. Malloc is a function which is used to allocate memory dynamically. It returns a pointer of type void which can be casted into pointer of any form.
   
```C
#include <stdio.h>

int main() {
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p);
    return 0;
}
```

Malloc does following operation with given input size_t N

1. Get a memory of size N from heap
2. clear that memory i.e. writing 0 to that memory for size N
3. return start address of the memory block 

Disadvantage 

1. Lets say memory of size N is allocated, no one is stoping from writing at memory location after those N bytes. Hence u may write into memory which is not assigned to you and may contain some other information. 

# difference between pointer and references 

# Dangling pointer 
Pointer pointing to memory location that has been free. 

```C

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    free(ptr); // Memory freed
    // Now ptr is a dangling pointer
    return 0;
}

```


# Memory Leaks 
means section of memory is wasted 
casues of memory leaks can be 
1. not calling free() when memory is of no use 
2. lost refernce 