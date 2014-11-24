#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

int main()
{
    void* handle;
    printf("calling dlopen...\n");
    handle = dlopen("somefile", 0 );
    printf("dlopen called.\n");
}
