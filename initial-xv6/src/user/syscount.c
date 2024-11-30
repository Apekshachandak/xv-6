#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        exit(1);
    }
    char *arr[25];
    arr[0] = " ";
    arr[1] = "fork";
    arr[2] = "exit";
    arr[3] = "wait";
    arr[4] = "pipe";
    arr[5] = "read";
    arr[6] = "kill";
    arr[7] = "exec";
    arr[8] = "fstat";
    arr[9] = "chdir";
    arr[10] = "dup";
    arr[11] = "getpid";
    arr[12] = "sbrk";
    arr[13] = "sleep";
    arr[14] = "uptime";
    arr[15] = "open";
    arr[16] = "write";
    arr[17] = "mknod";
    arr[18] = "unlink";
    arr[19] = "link";
    arr[20] = "mkdir";
    arr[21] = "close";
    arr[22] = "waitx";
    arr[23] = "getSysCount";
    arr[24] = "sigalarm";

    int mask = atoi(argv[1]);
    if (mask == 0)
    {
        exit(1);
    }

    int pid = fork();
    if (pid < 0)
    {
        exit(1);
    }

    if (pid == 0)
    {
        exec(argv[2], &argv[2]);

        exit(1);
    }
    else
    {
        wait(0);

        int syscall_num = 0;
        for (; mask % 2 != 1; syscall_num++, mask /= 2)
        {
        }

        int sys_count = getSysCount(mask);

        printf("PID %d called %s %d times.\n", pid, arr[syscall_num], sys_count);
    }

    exit(0);
}
