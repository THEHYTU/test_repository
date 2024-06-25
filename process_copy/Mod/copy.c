#include "process_copy.h"

#define BUFFER_SIZE 1024  // 定义缓冲区大小为1024字节


void copy_exec(const char *src, const char *dest, int blocksize, int offset) {
    int src_fd = open(src, O_RDONLY);  // 打开源文件，只读模式
    if (src_fd == -1) {  // 打开失败时报错并退出程序
        perror("Failed to open source file");
        exit(1);
    }

    int dest_fd = open(dest, O_WRONLY);  // 打开目标文件，只写模式
    if (dest_fd == -1) {  // 打开失败时报错并关闭已打开的源文件描述符，然后退出程序
        perror("Failed to open destination file");
        close(src_fd);
        exit(1);
    }

    // 设置源文件和目标文件的起始偏移量
    if (lseek(src_fd, offset, SEEK_SET) == -1) {  // 设置源文件偏移量失败时报错并关闭文件描述符
        perror("Failed to seek source file");
        close(src_fd);
        close(dest_fd);
        exit(1);
    }

    if (lseek(dest_fd, offset, SEEK_SET) == -1) {  // 设置目标文件偏移量失败时报错并关闭文件描述符
        perror("Failed to seek destination file");
        close(src_fd);
        close(dest_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];  // 定义用于存放读取和写入数据的缓冲区
    ssize_t bytes_read, bytes_written;  // 存放读取和写入的字节数
    int remaining = blocksize;  // 剩余要拷贝的字节数

    // 循环读取并写入数据，直到拷贝完成或发生错误
    while (remaining > 0 && (bytes_read = read(src_fd, buffer, (remaining < BUFFER_SIZE) ? remaining : BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);  // 写入数据到目标文件
        if (bytes_written == -1) {  // 写入失败时报错并关闭文件描述符
            perror("Failed to write to destination file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
        remaining -= bytes_read;  // 更新剩余要拷贝的字节数
    }

    close(src_fd);  // 关闭源文件描述符
    close(dest_fd);  // 关闭目标文件描述符

    printf("Process %d: Copied from %s to %s at offset %d.\n", getpid(), src, dest, offset);  // 打印拷贝完成的信息
}


int main(int argc, char **argv) {
    if (argc != 5) {  // 检查命令行参数数量是否正确，不正确则打印用法信息并返回错误码
        fprintf(stderr, "Usage: %s <src> <dest> <blocksize> <offset>\n", argv[0]);
        return 1;
    }

    const char *src = argv[1];  // 获取源文件路径
    const char *dest = argv[2];  // 获取目标文件路径
    int blocksize = atoi(argv[3]);  // 将块大小参数转换为整数
    int offset = atoi(argv[4]);  // 将偏移量参数转换为整数

    copy_exec(src, dest, blocksize, offset);  // 调用copy_exec函数进行文件拷贝操作

    return 0;  // 返回程序正常退出状态码
}

