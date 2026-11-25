#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: rmckpt <slot>\n");
        exit(1);
    }

    int slot = atoi(argv[1]);
    if (rmckpt(slot) < 0) {
        printf("rmckpt: failed to clear slot %d\n", slot);
        exit(1);
    }
    printf("Cleared slot %d\n", slot);
    exit(0);
}