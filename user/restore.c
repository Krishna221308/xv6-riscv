#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(int argc, char *argv[]) 
{
    int slot = argc > 1 ? atoi(argv[1]) : 0;

    if (argc > 2) {
        int fd = open(argv[2], O_RDONLY);
        if (fd < 0 || ckptload(slot, fd) < 0) {
            printf("restore: cannot load %s\n", argv[2]);
            exit(1);
        }
        close(fd);
    }

    if (restore(slot) < 0) {
        printf("restore: slot %d is empty", slot);
        exit(1);
    }

    wait(0);
    exit(0);
}
