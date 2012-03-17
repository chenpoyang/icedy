# 演示extern, index.c要引用其他文件extern.h里的数据或函数,则在index.c 中
# 以extern修饰,类似于声明(声明引用了外部的数据或函数),
# 但不用重新实现,在index.c中直接使用即可,比起直接引入头文件效率高
CC= gcc
CFLAGS= -O2 -Wall -g
RM= rm -f

ALL_T= index
ALL_OBJ= *.o

index: index.o extern.o
	$(CC) $(CFLAGS) -o index index.o extern.o

index.o: index.c
	$(CC) $(CFLAGS) -c index.c
extern.o: extern.h
	$(CC) $(CFLAGS) -c extern.c

.PHONY: clean

clean:
	$(RM) $(ALL_OBJ) $(ALL_T)
