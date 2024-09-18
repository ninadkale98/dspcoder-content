#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> 


sem_t semaphore ; 

void* routine(void *arg){
    printf("Hi from thread\n"); 
}

int main(){
    pthread_t th[4]; 
    sem_init(&semaphore, 0, 1); 

    for(int i = 0; i < 4 ; i++){
        pthread_create(&th[i], NULL, &routine, NULL); 
    }
    sleep(1); 
    
    for(int i = 0; i < 4 ; i++){
        pthread_join(&th[i], NULL); 
    }


    printf("Semaphore main\n"); 
    sem_destroy(&semaphore); 


}