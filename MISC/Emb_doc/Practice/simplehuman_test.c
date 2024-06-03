#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Descriptor
{
    int id;
    int name_length;
    char *name;
} Descriptor;

Descriptor *allocate_and_initialize_descriptor(int id, const char *name) 
{
    // Waiting to be implemented
    Descriptor *new_Descriptor; 
    // memset(new_Descriptor.name, 0, sizeof(char));
    new_Descriptor->id = id;
    new_Descriptor->name_length = sizeof(*name);
    new_Descriptor->name = name;
    
    return new_Descriptor;
}

void deallocate_descriptor(Descriptor *descriptor)
{
    free(descriptor);
    
}

#ifndef RunTests
int main()
{
    Descriptor *descriptor = allocate_and_initialize_descriptor(2, "File");
    printf("Id: %d, name length: %d, name: %s", descriptor->id, descriptor->name_length, descriptor->name);
    deallocate_descriptor(descriptor);
}
#endif





#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_letters( char **strings, int string_count, char target)
{
    // Waiting to be implemented
    
    int total_count = 0;
    
    for(int i = 0; i < string_count; i++){
        
        int len = sizeof(strings)/sizeof(char);
        printf("ss %d", len);
        
        for(int j = 0; j < len; j++){
            if(*strings[j] == target){
                total_count += 1;
            }
        }
    }
    
    return total_count;
}

int count_letters( char **strings, int string_count, char target){

    int count = 0;
    for(int i = 0; i < string_count; i++){
        int len = strlen(strings[i]);

        for(int j = 0; j < len ; j++){
            if(strings[i][j] == target){
                count += 1;
            }
        }
    }
}

#ifndef RunTests
int main()
{
    char *string_arr[] = {"Hello", "Jacqueline!"};
    int res = count_letters(string_arr, 2, 'e');
    printf("%d", res);
}
#endif