#include <stdio.h>
#include "hello.h"

int main(){
    int32_t t;
    printf("%s", "Hello World from main!");
    t = 0x5fffff;
    while(t-- > 0){}
    helloprint();
    t = 0x6ffffff;
    while(t-- > 0){}
    helloprint2();
    t = 0x7ffffff;
    while(t-- > 0){}
    printf("%s", "Bye!");
}