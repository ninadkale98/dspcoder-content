first thing first, include pthread library and while compiling using gcc pass -pthread flag as well

# Thread vs Process
    single process can have multiple threads
    threads me resources hote hai. think of it like single file me multiple functions saathe me run ho rahe parallely. like two functions can access and modify variable, similar hi hai yaha bhi kuch change nahi hai. just two functions running in parallel

    process on other hand is like i am running same .c file twice indenpently. dono resources alag use karenge. it like i am running two parallel .c files 

# Race condition 
     when two threads try to access and change same variable is called race condition. 

# Mutex 
    its like a lock. before accessing and modifying a variable for which race condition can happen. u check if lock is lockedor not. if not locked then u access it and before accessing make a lock varaible locked, set to 1. It allows only one thread at a time to access the shared resource, ensuring that data is not accessed inconsistently or concurrently by multiple threads, which could lead to data corruption or other issues.

    : check if lock is unlocked, wait until its unlocked and set it to locked 

    ## need to understand semaphore in detail : it is essitial a int variable used as lock 

# returning value from thread
    in pthread_join second argument is used for returning 

# trylock vs lock 
    trylock will try to get lock if it didnt get it wont wait like lock but exit with some return va;ue

# pthread_exit 
    it is same a return from thread 

# conditional variable pthread 
    lets say u have a varible which u need to check for some condition, but to access that u will need to have mutex. Now this will create an issue as others function which may update that variable will never get mutex. hence we have conditional variable which essentially releases mutex and wait for conditinal variable to get triggred, which will be done by some other function. 

# pthread_barriers
    lets se barrier count 3 hai, so jab tak 3 thread nahi aate koi execute nahi hoga. barrier will block execution till n numbers of threads not present. once n numbers is reached, all threads will be executed and barrier will again reset at zero and wait for next n threads

# detach vs join 
    Detach:
        Once detached, the main thread can continue its execution without waiting for the detached thread to finish.
        Detached threads cannot be joined. Attempting to join a detached thread will result in an error.
    Join:
        When a thread is joined, the main thread waits for the joined thread to finish before continuing its execution.
        Joining a thread allows the main thread to synchronize its execution with the joined thread, enabling coordination between threads.
        Joined threads cannot be detached. Attempting to detach a joined thread will result in an error.

# Deadlocks
    occurs when threads are waiting for each other to release the lock essentialing waiting forever. in single thread, if lock is called twice, thats a deadlock too as second pthred_utex_lock will wait for lock to be realesed which is hold by itself. 