#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main() {
    // 打开新文件且未指定O_CREAT标志
    int fd = open("test_file", O_RDWR, 0444);

    if (fd != -1) {
        printf("open(%s) succeeded unexpectedly", "test_file");
        return -1;
    }

    // 错误号errno标识错误原因
    if (errno != ENOENT) {
        printf("open() failed unexpectedly");
    } else {
        // 测试成功
        printf("open() failed as expected");
    }

    return 0;
}