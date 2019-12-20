#include "types.h"
#include "user.h"

int main(void) {
    int i = 0;
    while (i < 10) {
        fork();
        i++;
    }
    int j = 0;
    for (; j < 100; ++j) {
        printf(1, "[%d] : [%d]\n", getpid(), j);
    }

    exit();
}
