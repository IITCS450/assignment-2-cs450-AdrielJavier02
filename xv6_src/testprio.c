#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int pid = getpid();

  printf(1, "pid=%d\n", pid);

  if(setpriority(pid, 1) != 0)
    printf(1, "FAIL: setpriority(pid,1)\n");
  else
    printf(1, "OK: setpriority(pid,1)\n");

  if(setpriority(pid, 3) != -1)
    printf(1, "FAIL: setpriority(pid,3) should fail\n");
  else
    printf(1, "OK: invalid priority rejected\n");

  if(setpriority(999999, 1) != -1)
    printf(1, "FAIL: setpriority(badpid,1) should fail\n");
  else
    printf(1, "OK: invalid pid rejected\n");

  exit();
}

