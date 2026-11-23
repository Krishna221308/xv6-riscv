#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void) 
{
    int x = 100;
    for (int i = 1; i <= 8; ++i) {
        printf("n = %d, x = %d\n", i, x);
        if (i == 5) {
            int r = checkpoint(0);
            if (r == 1) {
                printf("[restored]\n");
            } 
            else {
                printf("[snapshot taken]\n");
            }
        }
        x++;
        pause(10);
    }
    exit(0);
}

