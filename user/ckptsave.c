#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int 
main(int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("Usage: ckptsave slot file\n");
        exit(1);
    }

    int fd = open(argv[2], O_CREATE | O_WRONLY | O_TRUNC);
    if (fd < 0) {
        printf("ckptsave: cannot open %s\n", argv[2]);
        exit(1);
    }

    if (ckptsave(atoi(argv[1]), fd) < 0) {
        printf("ckptsave: failed (empty slot?)\n");
        exit(1);
    }

    close(fd);
    printf("saved slot %s to %s\n", argv[1], argv[2]);
    exit(0);
}