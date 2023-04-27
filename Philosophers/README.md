We will allocate as many threads as the number of philosophers 
in one process and make a fork called a mutex to prevent simultaneous access.
A mutex allows only one thread to access a given resource.



# Reference

Explained each function with example code
https://42kchoi.tistory.com/301?category=966538

picture
https://velog.io/@meong9090/Philosophers-Philosophers%EA%B3%BC%EC%A0%9C-%EC%B4%9D-%EC%A0%95%EB%A6%AC#%EC%9D%B8%EC%9E%90


pthread_create
 After creating a thread, the created thread executes the function entered as an argument.

pthread_detach
 Executes the thread asynchronously, separate from the main process, and automatically releases all allocated resources when the thread's operation is finished.

pthread_join
 The main process waits for the thread to terminate, and automatically releases all allocated resources when the thread finishes.

difference between pthread_detach and pthread_join
 join waits for the thread to terminate
 but detach does not wait and excute next code

Mutex
 
https://reakwon.tistory.com/98
https://www.youtube.com/watch?v=oq29KUy29iQ

pthread_mutex_init
 create mutex object

pthread_mutex_destroy
 release mutex object

pthread_mutex_lock
 A function to protect shared resources using a mutex. If another process executes the function while another thread or process is executing the function, it waits in the queue until the thread or process executing the function unlocks it.

pthread_mutex_unlock
 A function to protect shared resources using a mutex. When the use of shared resources ends, mutex is returned to allow other threads or processes to access the shared resources.