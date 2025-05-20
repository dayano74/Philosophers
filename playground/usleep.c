/**
 * @brief Documentation for usleep function
 * 
 * usleep() suspends execution of the calling thread for at least the specified
 * number of microseconds.
 * 
 * @param usec Number of microseconds to sleep (1 second = 1,000,000 microseconds)
 * @return 0 on success, -1 on error
 * 
 * @note 1 microsecond = 10^-6 seconds
 */

#include <unistd.h>
#include <stdio.h>


int main() {
    usleep(1000000); // Sleep for 1 second
    printf("Hello, World!\n");
    return 0;
}

