#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 

pthread_mutex_t mutex; 

int common_variable = 0; 

void* routine(void *arg){

    int thread_num = *(int *) arg;

    while(1){
        
        pthread_mutex_lock(&mutex); 
        common_variable += 1; 
        printf("Thread %d \t %d\n", thread_num ,common_variable); 
        pthread_mutex_unlock(&mutex); 
        sleep(1); 

    }
    
}

int main(int agrc , char* argv[]){
    printf("hello world\n"); 
    printf("Total argument passed : %d\n", agrc); 

    pthread_t thread1; 
    pthread_t thread2; 
    pthread_mutex_init(&mutex, NULL);
    
    int thread_id_1 = 1; 
    int thread_id_2 = 2; 

    pthread_attr_t attr1, attr2;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);

    // Set different priorities for thread1 and thread2
    struct sched_param param1, param2;
    param1.sched_priority = 1; // lower priority
    param2.sched_priority = 99; // higher priority

    pthread_attr_setschedparam(&attr1, &param1);
    pthread_attr_setschedparam(&attr2, &param2);
    

    // pointer to thread | attributes of thread | function name | parameters 
    pthread_create( &thread1 , &attr1, &routine, &thread_id_1); 
    pthread_create( &thread2 , &attr2, &routine, &thread_id_2); 


    // run indefinetly 
    pthread_join(thread1, NULL); 
    pthread_join(thread1, NULL); 
    
    pthread_mutex_destroy(&mutex);

    
    return 0; 
}