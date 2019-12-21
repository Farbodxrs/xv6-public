#include "types.h"
#include "user.h"

struct timeVariables {
    uint creationTime;
    uint terminationTime;
    uint sleepingTime;
    uint readyTime;
    uint runningTime;
} t;

int main(void) {
    fork();
    fork();
    fork();

    waitForChild(&t);
    waitForChild(&t);

    printf(1, "CREATION TIME[%d] : %d\n", getpid(), t.creationTime);

    exit();
}
