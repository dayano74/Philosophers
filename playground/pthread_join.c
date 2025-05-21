/**
 * @bried Documentation for pthread_join function
 * 
 * pthread_join() blocks the calling thread until the specified thread terminates.
 * protype: int pthread_join(pthread_t thread, void **retval);
 * 
 * @param thread The thread ID to join
 * @param retval Pointer to a location to store the return value of the thread
 * @return 0 on success, error code on failure
 */

/**
 * @brief Simple Thread Joining Demo
 * 
 * This program demonstrates how to join a thread and retrieve its return value.
 * 
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// Thread function that returns a string
void* thread_function(void* arg) {
    char* message = (char*)arg;
    printf("Thread received message: %s\n", message);
    sleep(1);
    return (void*)message;
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    char* message;

    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }
    message = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 1));
    strcpy(message, argv[1]);
    printf("Main thread: Creating thread with message: %s\n", message);
    pthread_create(&thread, NULL, thread_function, (void*)message);
    pthread_join(thread, (void**)&message);
    printf("Main thread: Thread joined with message: %s\n", message);
    free(message);
    return 0;
}