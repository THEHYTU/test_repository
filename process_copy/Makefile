# Makefile

# 编译器
CC := gcc

# 编译选项
CFLAGS := -Wall -Wextra

# 头文件路径
INCLUDE := -I./include

# 目标文件
TARGET := process_copy
COPY_EXEC := copy_exec

# 源文件目录和重载文件的目录
SRC_DIR := source
MOD_DIR := Mod

# 文件列表
SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS += $(wildcard $(MOD_DIR)/*.c)

# 排除 copy.c 文件，因为它包含了与 process_copy 中重复的 main 函数
SRCS := $(filter-out $(MOD_DIR)/copy.c, $(SRCS))

# 对象文件列表
OBJS := $(SRCS:.c=.o)

# 默认目标
all: $(TARGET) $(COPY_EXEC)

# 生成可执行文件 process_copy
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

# 生成 copy_exec 可执行文件
$(COPY_EXEC): $(MOD_DIR)/copy.c
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

# 编译所有的 .c 文件为 .o 文件
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(COPY_EXEC) $(OBJS)

# 默认情况下，不删除生成的可执行文件
.PHONY: clean

