#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;
 
void *f(void *ptr) {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
        usleep(100000);
    }
    pthread_exit(0);
}
 
int main()
{
    pthread_t tid, tid2;
    pthread_create(&tid, NULL, f, NULL); // utworzy nam watek z identyfikatorem tid
    pthread_create(&tid2, NULL, f, NULL);
    pthread_join(tid, NULL);             // wymaga podania identyfikatora watku
    pthread_join(tid2, NULL);
    return 0;
}