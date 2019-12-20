#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void) {
    return fork();
}

int
sys_exit(void) {
    exit();
    return 0;  // not reached
}

int
sys_wait(void) {
    return wait();
}

int
sys_kill(void) {
    int pid;

    if (argint(0, &pid) < 0)
        return -1;
    return kill(pid);
}

int
sys_getpid(void) {
    return myproc()->pid;
}

int
sys_sbrk(void) {
    int addr;
    int n;

    if (argint(0, &n) < 0)
        return -1;
    addr = myproc()->sz;
    if (growproc(n) < 0)
        return -1;
    return addr;
}

int
sys_sleep(void) {
    int n;
    uint ticks0;

    if (argint(0, &n) < 0)
        return -1;
    acquire(&tickslock);
    ticks0 = ticks;
    while (ticks - ticks0 < n) {
        if (myproc()->killed) {
            release(&tickslock);
            return -1;
        }
        sleep(&ticks, &tickslock);
    }
    release(&tickslock);
    return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void) {
    uint xticks;

    acquire(&tickslock);
    xticks = ticks;
    release(&tickslock);
    return xticks;
}

int
sys_getppid(void) {
    return myproc()->parent->pid;
}

int
sys_getchildren(void) {
    int num;
    argptr(0, (void *) &num, sizeof(num)); // extract and store argument into num
    return getchild(num); // call get child method in proc.c
}

int
sys_getcalledcount(void) {
    int num;
    argptr(0, (void *) &num, sizeof(num)); // extract and store argument into num
    return getcalled(num); // call get child method in proc.c
}


int
sys_changepriority(void) {
    int num;
    argptr(0, (void *) &num, sizeof(num)); // extract and store argument into num
    if (num > 5 || num < 1) {
        return -1;
    }
    //cprintf("CPRINTF : priority before is  : %d",myproc()->priority);
    myproc()->priority = num;
    //cprintf("CPRINTF : priority after is  : %d",myproc()->priority);
    if (myproc()->priority == num) {
        return 1;
    }
    return 1;
}


int
sys_changepolicy(void) {
    int num;
    argptr(0, (void *) &num, sizeof(num)); // extract and store argument into num
    cprintf("THSI IS CPRINTF");
    return num * 3;
    if (num < 0 || num > 3) {
        return -1;
    }
    setAlgo(num);
    if (getAlgo() == num) {
        return 1;
    }
    return -1;

}

int
sys_fpolicy(void) {
    int num;
    argptr(0, (void *) &num, sizeof(num)); // extract and store argument into num
    return num * 5;
}
