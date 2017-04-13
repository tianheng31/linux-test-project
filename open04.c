#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main() {
    // 非特权进程，以O_NOATIME标志打开文件时，open()调用失败，返回错误
    // 事先设置了startup的拥有者不是此进程的有效用户ID
    int fd = open("startup", O_RDONLY | O_NOATIME, 0444);

    if (fd != -1) {
        printf("open(%s) succeeded unexpectedly", "startup");
        return -1;
    }

    // 错误号errno标识错误原因
    if (errno != EPERM) {
        printf("open() failed unexpectedly");
    } else {
        // 测试成功
        printf("open() failed as expected");
    }

    return 0;
}