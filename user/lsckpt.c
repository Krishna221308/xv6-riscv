#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  struct ckpt_info info;
  printf("=== Checkpoint Slots ===\n");
  for (int i = 0; i < 4; i++) {
    if (ckptinfo(i, &info) < 0)
      continue;
    if (info.used) {
      printf("Slot %d: [USED]  process: '%s'  size: %d bytes\n", i, info.name, (int)info.sz);
    } else {
      printf("Slot %d: [EMPTY]\n", i);
    }
  }
  exit(0);
}