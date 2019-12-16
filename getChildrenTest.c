#include "types.h"
#include "user.h"

int main(void) {

    fork();
    fork();
    wait();
    printf(1, "process : pid()= %d ppid()= %d getChildren(getppid())= %d\n", getpid(), getppid(),getchildren(getppid()));
    wait();
    exit();
}
