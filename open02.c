#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    // 判断一个文件是不是目录
    int fd = open("/tmp", O_DIRECTORY); // 目录
    struct stat statbuf; // 描述文件属性
    unsigned short filmode;
    fstat(fd, &statbuf); // 返回由文件描述符所指代文件的相关信息
    filmode = statbuf.st_mode;
    if (!(filmode & S_IFDIR)) {
        printf("directory bit cleared");
    } else {
        // 是目录
        printf("directory bit is set");
    }
}