#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *ptr)
{
    char *text;
    text = (char *)ptr;
    printf("&s \n", text);
    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    char *str1 = "I am thread 1";
    char *str2 = "I am thread 2";

    int t1ret, t2ret;

    t1ret = pthread_create(&thread1, NULL, print_message, (void*) str1);
    t2ret = pthread_create(&thread2, NULL, print_message, (void*) str2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("t1 & t2 return: %d %d", t1ret, t2ret);

    return 0;

}