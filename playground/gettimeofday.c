/**
 * @brief Documentation for gettimeofday function
 * 
 * gettimeofday() returns the current time in seconds and microseconds since the Epoch.
 * 
 * @param tv Pointer to a struct timeval variable containing:
 *          - tv_sec: seconds since the Epoch
 *          - tv_usec: microseconds
 * @param tz Pointer to a struct timezone variable containing:
 *          - tz_minuteswest: minutes west of Greenwich
 *          - tz_dsttime: daylight saving time
 * @return 0 on success, -1 on error
 * 
 * @note The timezone parameter is obsolete and should be NULL in modern applications
 */

// Example usage:
#include <unistd.h>  // for sleep()
#include <sys/time.h>   // for gettimeofday()
#include <stdio.h>

void print_cur_jpn_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long japan_sec = tv.tv_sec + (9 * 3600); // Add 9 hours in seconds
    int japan_hour = (japan_sec / 3600) % 24; // Ensure hours wrap around 24
    int japan_minute = (japan_sec % 3600) / 60;
    int japan_second = japan_sec % 60;
    printf("Current time in Japan: %02d:%02d:%02d.%06ld\n", japan_hour, japan_minute, japan_second, tv.tv_usec);
}

int main() {
    print_cur_jpn_time();
    sleep(3);
    print_cur_jpn_time();
    return 0;
}
