#include "process_copy.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

void process_create(const char *src, const char *dest, int pronum, int blocksize) {
    pid_t pid;

    // 先创建目标文件
    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Failed to create destination file");
        exit(1);
    }
    close(dest_fd);

    for (int i = 0; i < pronum; ++i) {
        pid = fork();

        if (pid == 0) { // 子进程
            int offset = i * blocksize;
            char offset_str[20], blocksize_str[20];
            snprintf(offset_str, sizeof(offset_str), "%d", offset);
            snprintf(blocksize_str, sizeof(blocksize_str), "%d", blocksize);

            execl("copy_exec", "copy_exec", src, dest, blocksize_str, offset_str, (char *)NULL);
            perror("Failed to exec copy_exec");
            exit(1);
        } else if (pid < 0) { // 出错处理
            perror("Failed to fork process");
            exit(1);
        }
    }

    // 等待所有子进程结束
    for (int i = 0; i < pronum; ++i) {
        wait(NULL);
    }

    printf("All processes have completed.\n");
}

