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
        // lock ~ unlock の中の処理を動かせるのは1人だけ。lock()で待機する。
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

	// 歩行者信号の設置 initで、最初unlock状態がセットされる。単純なboolではなさそう。
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);

    // pthreadに、 cnt と mutex を渡したいので構造体にいれる。
	t_mut t;
	t.mutex = &mutex;
	t.cnt = &cnt;

	// 関数を勝手に走らせる。並列処理。
	pthread_create(&thread1, NULL, &f, &t);
	pthread_create(&thread2, NULL, &f, &t);

	// 終了するまで待機。createとセット
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("*t.cnt: %d\n", *t.cnt);
}