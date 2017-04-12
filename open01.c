#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    // 创建一个新的空文件
    int fd = open("startup", O_RDWR | O_CREAT, 01444); // 设置新文件的权限
    struct stat statbuf; // 描述文件属性
    unsigned short filmode;
    fstat(fd, &statbuf); // 返回由文件描述符所指代文件的相关信息
    filmode = statbuf.st_mode;
    if (!(filmode & S_ISVTX)) {
        printf("Save text bit cleared");
    } else {
        // 成功设置了粘滞位
        printf("Save text bit not cleared");
    }
}