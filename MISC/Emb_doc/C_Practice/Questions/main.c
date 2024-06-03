#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPallin(char *s){
    char *left_pointer;

    left_pointer = s;
    while (*s != '\0')
    {
        s++ ;
    }
    char *right_pointer = s-1;

    while (right_pointer > left_pointer){
        if(*left_pointer == *right_pointer){
            left_pointer += 1;
            right_pointer -= 1; 
        }
        else{
            return false;
        }
    }

    return true;

};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *output = (int*)malloc(2 * sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if ((nums[i] + nums[j] ) == target && i != j){
                output[0] = i;
                output[1] = j;
                return output;
            }
        }
    }
    return output;
}

int main(){

    printf("ddjkjh \n");

    int *out = twoSum((int[]){2, 7, 11, 15}, 4, 9, (int[]){2}); 

    out++;
    printf("hjhgh %d %d", *(out-1), *out);

}