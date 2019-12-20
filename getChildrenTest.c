#include "types.h"
#include "user.h"

int main(void) {

    int a = fork();
    int b = fork();
    if (a > 0) {
        //parent
        sleep(30);
    }

    if (b > 0) {
        sleep(20);
    }
    printf(1, "process : pid()= %d ppid()= %d getChildren(getppid())= %d\n", getpid(), getppid(),getchildren(getppid()));
    wait();
    wait();
    exit();
}
