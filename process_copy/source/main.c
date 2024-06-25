// source/main.c

#include "process_copy.h"


int main(int argc, char** argv) {
  int pronum = (argc == 4) ? atoi(argv[3]) : 5; // 默认进程数为5
    if (check_pram(argc, argv[1], pronum)==-1) {
        return -1;
    }

    int blocksize = blocksize_cur(argv[1], pronum);

    if (blocksize == -1) {
        fprintf(stderr, "Failed to calculate blocksize.\n");
        return -1;
    }

    // 调用 process_create 函数来创建进程并进行文件拷贝
    process_create(argv[1], argv[2], pronum, blocksize);

    return 0;
}



