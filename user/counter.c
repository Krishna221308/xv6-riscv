#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

int
main(void) 
{
    int fd = open("log.txt", O_CREATE | O_WRONLY);
    char msg[] = "hello\n";
    write(fd, msg, sizeof(msg) - 1);

    printf("Before checkpoint: %s", msg);
    checkpoint(0);
    printf("After checkpoint: %s", msg);

    char msg2[] = "world after checkpoint\n";
    write(fd, msg2, sizeof(msg2) - 1);

    close(fd);

    printf("New content: %s", msg2);

    exit(0);
}