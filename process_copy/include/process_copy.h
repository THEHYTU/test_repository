
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include<stdlib.h>

int check_pram(int argc, const char* src, int pronum);
int blocksize_cur(const char* src, int pronum);
void process_create(const char* src, const char* dest, int pronum, int blocksize);
void process_wait();
void copy_exec(const char *src, const char *dest, int blocksize, int offset);
