#include <stdio.h>
#include <pthread.h>
#include <unistd.h>  // usleepのために追加

/*
** mainで宣言したcntを、10000カウントアップするだけの関数。
** 明示的に分離して競合を発生させやすくする
*/
void *f(void *p)
{
	int	*cnt;
	int temp;

	cnt = p;
	for (int i = 0; i < 10000; ++i) {
		temp = *cnt;     // 読み込み
		usleep(0.2);      // スレッド切り替えが起きやすくなる
		temp = temp + 1; // 加算処理
		*cnt = temp;     // 書き込み
	}
	return (NULL);
}

int main()
{
	int cnt = 0;
	pthread_t thread1;
	pthread_t thread2;

	// mainの処理とは別に働かせる。並列処理。
	pthread_create(&thread1, NULL, &f, &cnt);
	pthread_create(&thread2, NULL, &f, &cnt);

	// 終了するまで待機。pthread_createとセット
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("cnt: %d\n", cnt); // 20000が出ないはず
}