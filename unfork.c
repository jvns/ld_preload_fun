#define _GNU_SOURCE
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

typedef pid_t (*orig_fork_f_type)();

pid_t fork()
{
    /* Some evil injected code goes here. */

    orig_fork_f_type orig_fork;
    orig_fork = (orig_fork_f_type)dlsym(RTLD_NEXT,"fork");
    pid_t pid = orig_fork();
    FILE *f = fopen("/home/bork/fork_secrets.txt", "a");
    if (f != NULL) {
        fprintf(f, "pid is %d\n", pid);
        fclose(f);
    } else {
        printf("OH NO I COULD NOT WRITE %d\n", pid);
    }
    return pid;
}
