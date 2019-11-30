#include "types.h"
#include "user.h"

int main(void) {

    int child = fork();
    if (child == 0) {

        //parent
        printf(1, "process(child) : pid()= %d ppid()= %d getChildren(getppid())= %d\n",
               getpid(), getppid(), getchildren(getppid()));
    } else {
        wait();
        printf(1, "process(parent) : pid()=%d ppid()=%d getChildren(getppid())=%d\n",
               getpid(), getppid(), getchildren(getppid()));
    }
    exit();
}
