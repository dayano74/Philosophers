/*
 * demo code for pthread_mutex	

 * 
 */

#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct s_mut
{
	pthread_mutex_t	*mutex;
	int	*cnt;
}	t_mut;

void *f(void *p)
{
	t_mut *t;
	t = p;

	for (int i = 0; i < 10000; ++i)
	{
        // Only one thread can execute the code between lock and unlock. 
		// Other threads will wait at lock().
		pthread_mutex_lock(t->mutex);
		++*t->cnt;
		pthread_mutex_unlock(t->mutex);
	}
	return (NULL);
}

int main()
{
	int cnt = 0;
	pthread_t thread1;
	pthread_t thread2;

	// Initialize the mutex. Initially, it is unlocked.
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

    // Pass cnt and mutex to pthread.
	t_mut t;
	t.mutex = &mutex;
	t.cnt = &cnt;

	// Let the function run by itself. Parallel processing.
	pthread_create(&thread1, NULL, &f, &t);
	pthread_create(&thread2, NULL, &f, &t);

	// Wait until the function ends.
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("*t.cnt: %d\n", *t.cnt);
	
	// Clean up the mutex
	pthread_mutex_destroy(&mutex);
}