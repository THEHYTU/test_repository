#include "process_copy.h"

int check_pram(int argc, const char* src, int pronum) {
    // 参数校验
    if (argc < 3 || argc > 4) {
        printf("参数不合法\n");
        return 0;
    }
    // 进程数校验
    if (pronum > 200 || pronum <= 0) {
        printf("进程数不合法\n");
        return -1;
    }
    // 文件校验
    if (access(src, F_OK) == 0) {
        printf("File '%s' exists.\n", src);
    } else {
        printf("File '%s' does not exist or cannot be accessed.\n", src);
        return -1;
    }
    return 0;
}

