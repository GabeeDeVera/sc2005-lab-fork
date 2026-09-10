#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    fprintf(2, "proccount: %d processes currently not unused\n", getproccount());

    exit(0);
}
