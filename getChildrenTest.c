#include "types.h"
#include "user.h"

int main(void) {

    int child = fork();
    if(child < 0){
        printf(1, "fork error");
        exit();
    }
    if (child == 0) {
        //parent
        wait();
        printf(1, "process(child) : pid()= %d ppid()= %d getChildren(getppid())= %d\n", getpid(), getppid(), getchildren(getppid()));
    } if(child > 0){
        //child

        printf(1, "process(parent) : pid()=%d ppid()=%d getChildren(getppid())=%d\n",
               getpid(), getppid(), getchildren(getppid()));
    }
    exit();
}
