#include "types.h"
#include "user.h"


struct timeVariables {
    uint creationTime;
    uint terminationTime;
    uint sleepingTime;
    uint readyTime;
    uint runningTime;
} t[10000];


int main(void) {
    fpolicy(2);//modified xv6 original
    ;
    int i[1000];
    while (i < 5) {
        fork();
        i++;
    }
    changepriority();
    for (; j < 1000; ++j) {
        printf(1, "[%d] : [%d]\n", getpid(), j);
    }
    waitForChild(&t[getpid()]);


}

exit();

}
