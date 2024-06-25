#include "process_copy.h"


int blocksize_cur(const char* src, int pronum) {
printf("获取blocksize\n");
    int fd = open(src, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // 获取文件大小
    int fsize = lseek(fd, 0, SEEK_END);
    if (fsize == -1) {
        perror("lseek");
        close(fd);
        return -1;
    }

    close(fd);

    // 获取工作量
    int blocksize = fsize / pronum;
    if (fsize % pronum != 0) {
        blocksize++;
    }

    return blocksize;
}

