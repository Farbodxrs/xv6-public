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
    t.runningTime = 6;
    t.readyTime = 9;
    t.sleepingTime = 2;
    t.terminationTime = 3;
    t.creationTime = 5;

    int i = waitForChild(&t);
    printf(1, "WAIT FOR CHILD %d \n", i);

    exit();
}
