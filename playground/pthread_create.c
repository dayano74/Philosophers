/**
 * @brief Documentation for pthread_create function
 * 
 * pthread_create() creates a new thread and starts it executing the function specified by attr.
 * protype: int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg);
 * 
 * @param thread Pointer to the pthread_t variable that will hold the new thread's ID
 * @param attr Pointer to a pthread_attr_t structure that specifies the thread's attributes
 * @param start_routine Pointer to the function that the new thread will execute
 */

/**
 * @brief Simple Thread Benefits Demo (Easy Implementation)
 * 
 * This program explains the main benefits of threads:
 * 1. Multiple tasks can be executed simultaneously
 * 2. Each task operates independently without interfering with others
 * 
 * @note Compilation: gcc -pthread pthread_create.c
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // for sleep function

// Thread 1: Performs a countdown
void *countdown_task(void *arg) {
    char *name = (char*)arg;
    printf("🕒 %s countdown started!\n", name);
    
    for (int i = 5; i > 0; i--) {
        printf("🕒 %s: %d\n", name, i);
        sleep(1); // wait 1 second
    }
    
    printf("🎉 %s countdown finished!\n", name);
    return NULL;
}

// Thread 2: Displays different messages
void *message_task(void *arg) {
    (void)arg;
    printf("📝 Message task started!\n");
    
    char *messages[] = {
        "Threads can handle multiple tasks",
        "Multiple processes can run simultaneously",
        "The countdown is still progressing during this time",
        "The main program is also running at the same time",
        "This is the biggest benefit of threads"
    };
    
    for (int i = 0; i < 5; i++) {
        printf("📝 Message: %s\n", messages[i]);
        sleep(1); // wait 1 second
    }
    
    printf("📝 Message task finished!\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    printf("\n===== Thread Benefits Demo (Simple Version) =====\n\n");
    printf("Main program: Running two tasks simultaneously\n");
    
    // Create two threads and run them simultaneously
    pthread_create(&thread1, NULL, countdown_task, "Counter");
    pthread_create(&thread2, NULL, message_task, NULL);
    
    // Also display messages in the main thread
    for (int i = 0; i < 7; i++) {
        printf("🔄 Main: Main program is still running...\n");
        sleep(1);
    }
    
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("\n===== Result Explanation =====\n");
    printf("1. Three processes (main, countdown, messages) ran simultaneously\n");
    printf("2. Each process operated independently without affecting others\n");
    printf("3. This is the main benefit of threads: Concurrent Processing\n");
    printf("4. On multi-core CPUs, multiple tasks can truly run simultaneously\n");
    
    return 0;
}