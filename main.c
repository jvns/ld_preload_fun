#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *f = fopen("/home/bork/main_secrets.txt", "a");
    if (f != NULL) {
        fprintf(f, "number is %d\n", rand() % 100);
        fclose(f);
    }
}
