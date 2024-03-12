#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;

void *inc_gv()
{
    int i,j;
    for(i=0;i<10;i++){
        g_var1++;
        for(j=0;j<5000000;j++);
        printf(" %d", g_var1);
        fflush(stdout);
    }
}

int main(){
    pthread_t threadA, threadB;
    int tAret, tBret;

    tAret = pthread_create(&threadA, NULL, inc_gv, NULL);
    tBret = pthread_create(&threadB, NULL, inc_gv, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);

    printf("t1 & t2 return: %d %d", tAret, tBret);

    printf("\n pthread2 completed \n");
}