/**
 * @brief Documentation for pthread_detach function
 * 
 * pthread_detach() marks the thread specified by thread as detached.
 * When a detached thread terminates, its resources are automatically released back to the system
 * without the need for another thread to join with it.
 * 
 * prototype: int pthread_detach(pthread_t thread);
 * 
 * @param thread The thread ID to detach
 * @return 0 on success, error code on failure
 */

/**
 * @brief Thread Detachment Demo
 * 
 * This program demonstrates the difference between:
 * 1. Detached threads (automatically release resources when they finish)
 * 2. Joinable threads (must be explicitly joined to release resources)
 * 
 * @note Compilation: gcc -pthread pthread_detach.c
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Global flag to track the main thread's execution
volatile int main_running = 1;

// Thread function for detached thread
void* detached_thread_function(void* arg) {
    int id = *((int*)arg);
    free(arg); // Free the memory allocated in main
    
    printf("🚀 Detached thread %d started\n", id);
    
    for (int i = 1; i <= 3; i++) {
        printf("🚀 Detached thread %d: Working... (%d/3)\n", id, i);
        sleep(1);
    }
    
    printf("🚀 Detached thread %d finished. Resources automatically released!\n", id);
    
    return NULL;
}

// Thread function for joinable thread
void* joinable_thread_function(void* arg) {
    int id = *((int*)arg);
    
    printf("🔄 Joinable thread %d started\n", id);
    
    for (int i = 1; i <= 3; i++) {
        printf("🔄 Joinable thread %d: Working... (%d/3)\n", id, i);
        sleep(1);
    }
    
    printf("🔄 Joinable thread %d finished. Resources NOT yet released!\n", id);
    
    return arg; // Return the memory so it can be freed in main
}

// Monitor thread that will outlive the main thread
void* monitor_thread_function(void* arg) {
    (void)arg;
    printf("👀 Monitor thread started (will outlive main)\n");
    
    while (main_running) {
        printf("👀 Monitor: Main thread is still running...\n");
        sleep(1);
    }
    
    printf("👀 Monitor: Main thread has exited!\n");
    printf("👀 Monitor: Waiting to see if detached threads complete...\n");
    
    // Wait a bit more to see the detached threads finish
    sleep(5);
    
    printf("👀 Monitor: Demo completed. Detached threads should be done!\n");
    return NULL;
}

int main() {
    pthread_t detached_thread1, detached_thread2, joinable_thread, monitor_thread;
    
    printf("\n===== Thread Detachment Demo =====\n\n");
    printf("Main: Creating threads to demonstrate detached vs joinable behavior\n\n");
    
    // Create monitor thread (detached)
    pthread_create(&monitor_thread, NULL, monitor_thread_function, NULL);
    pthread_detach(monitor_thread);
    
    // Create and detach two threads
    int* id1 = malloc(sizeof(int));
    *id1 = 1;
    pthread_create(&detached_thread1, NULL, detached_thread_function, id1);
    pthread_detach(detached_thread1);
    printf("Main: Created and detached thread 1\n");

    int* id2 = malloc(sizeof(int));
    *id2 = 2;
    pthread_create(&detached_thread2, NULL, detached_thread_function, id2);
    pthread_detach(detached_thread2);
    printf("Main: Created and detached thread 2\n");
    
    // Create a joinable thread
    int* id = malloc(sizeof(int));
    *id = 3;
    pthread_create(&joinable_thread, NULL, joinable_thread_function, id);
    printf("Main: Created joinable thread (not detached)\n\n");
    
    printf("Main: Sleeping for 2 seconds while threads run...\n");
    sleep(2);
    
    // Join with the joinable thread (wait for it to finish)
    void* result;
    printf("\nMain: Now joining with the joinable thread (will wait for it)\n");
    pthread_join(joinable_thread, &result);
    
    // Free the memory returned by the joinable thread
    printf("Main: Joinable thread completed, freeing its resources\n");
    free(result);
    
    printf("\n===== Key Points About pthread_detach =====\n");
    printf("1. Detached threads release their resources automatically when they finish\n");
    printf("2. The main program doesn't need to call pthread_join on detached threads\n");
    printf("3. You cannot join with a detached thread (it would cause undefined behavior)\n");
    printf("4. Use detached threads for 'fire and forget' operations\n");
    printf("5. Detached threads can continue running even after main() finishes\n\n");
    
    printf("Main: Now exiting. The monitor and any remaining detached threads continue...\n");
    main_running = 0; // Signal to the monitor thread that main is done
    
    return 0;
}
