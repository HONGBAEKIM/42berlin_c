We will allocate as many threads as the number of philosophers 
in one process and make a fork called a mutex to prevent simultaneous access.
A mutex allows only one thread to access a given resource.



# Reference

Explained each function with example code
https://42kchoi.tistory.com/301?category=966538

Evalution
https://velog.io/@kurtyoon/42-Philosophers

picture
https://velog.io/@meong9090/Philosophers-Philosophers%EA%B3%BC%EC%A0%9C-%EC%B4%9D-%EC%A0%95%EB%A6%AC#%EC%9D%B8%EC%9E%90

What is a Thread?
 An execution thread is a logical sequence of instructions inside a process that is automatically managed by the operating system’s kernel

pthread_create
 After creating a thread, the created thread executes the function entered as an argument.

(ex) pthread_create(&philo->t1, NULL, &supervisor, (void *)philo)

    philo->t1: a pointer towards a pthread_t type variable, to store the ID of the philo->t1 we will be creating.
    
    NULL: an argument that allows us to change the default attributes of the new thread. 
        in general, passing NULL here suffices.
    
    supervisor: the function where the philo->t1 will start its execution. This function will have as its prototype: void *function_name(void *arg);. When the philo->t1 reaches the end of this function, it will be done with its tasks.
    
    philo: a pointer towards an argument to pass to the philo->t1’s start_routine function. If we’d like to pass several parameters to this function, we will need to give it a pointer to a data structure.



pthread_detach
 Executes the thread asynchronously, separate from the main process, and automatically releases all allocated resources when the thread's operation is finished.

(ex) pthread_detach(data->tid[0])

    Here, all we have to supply if the data->tid[0]’s ID. We get 0 in return if the operation was a success, or non-zero if there was an error. After detaching the thread, other threads will not be able to kill or wait for this thread with pthread_join.


pthread_join
 The main process waits for the thread to terminate, and automatically releases all allocated resources when the thread finishes.

(ex) pthread_join(philo->t1, NULL)

    philo->t1: the ID of the philo->t1 that this thread should wait for. The specified thread must be joinable (meaning not detached – see below).
    
    NULL: a pointer towards a variable that can contain the return value of the thread’s routine function (the start_routine function we supplied at its creation). 

 The pthread_join function returns 0 for success, or an error code for failure.

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



Evaluation PDF
