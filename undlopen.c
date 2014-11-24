#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

void* dlopen(const char *file, int mode)
{
    static void* (*o_dlopen) ( const char *file, int mode )=0;
    printf( "dlopen was called with file %s\n" , file);
    o_dlopen = (void*(*)(const char *file, int mode)) dlsym(RTLD_NEXT,
"dlopen");
    return (*o_dlopen)( file, mode );
}
