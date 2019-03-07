#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;
 
/*
  ulotna zmienna dla optymalizatora - volatile 
  segment danych ten sam dla calego procesu - static
  stos dla kazdego watku osobny - auto


  pthread_mutex_lock(&m);
  pthread_mutex_unlock(&m);
  pthread_mutex_trylock(&m); raczej nie uzywac, oznacza to ze nie potrafimy dobrze zorganizowac swojego kodu

  pthread_cond_t c = PTHREAD_COND_INITIALIZER
  pthread_cond_wait(&c);
  pthread_cond_signal(&c);
  pthread_cond_broadcast(&c);
*/

#define MAX 5

int buf[MAX];
int count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t c2 = PTHREAD_COND_INITIALIZER;

void *f(void *ptr) {
  static volatile int i = 0;
  for (i = 0; i < 10; i++) {
    printf("%d", i);
    fflush(0);
  }
   pthread_exit(0);
   return 0;
}

void *producer(void *ptr) {
  int i;
  for (i = 0; i < 100; i++) {
    pthread_mutex_lock(&m);
    while (count >= MAX) pthread_cond_wait(&c1, &m);   // drugim parametrem jest mutex na ktory czekamy. na czas waita zwalniam mutex
    
    buf[i%MAX] = i;
    count++;
    pthread_cond_signal(&c2);
    pthread_mutex_unlock(&m);
  }
}

void *consumer(void *ptr) {
  int i;
  for (i = 0; i < 100; i++) {
    pthread_mutex_lock(&m);
    while (count <= 0) pthread_cond_wait(&c2, &m);

    printf("%d\n", buf[i%MAX]);
    count--;
    pthread_cond_signal(&c1);
    pthread_mutex_unlock(&m);
  }
}
 
int main()
{
  pthread_t tid, tid2;
  pthread_create(&tid, NULL, producer, NULL); // utworzy nam watek z identyfikatorem tid
  pthread_create(&tid2, NULL, consumer, NULL);
  pthread_join(tid, NULL);             // wymaga podania identyfikatora watku
  pthread_join(tid2, NULL);

  cout << endl;
  return 0;
}