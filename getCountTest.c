#include"types.h"
#include "user.h"

long strtol(const char *nptr, char **endptr, register int base);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf(1, "You must provide one argument\n");
        exit();
    }
    int input = atoi(argv[1]);

    int a = getppid();
    a = getppid();
    a = getppid();
    a = getppid();

    int res = getcalledcount(input);
    printf(1, "desired sys call, called : %d times \n", res);


    //this following line is because of this err : error: variable 'a' set but not used [-Werror=unused-but-set-variable]
    if(a>5)
        exit();

    exit();
}
