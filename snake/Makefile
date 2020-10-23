SRC = $(wildcard src/*c)

CC = gcc

INFLAGS = -I ./include 	#指定头文件的路径
LDFLAGS =  -lcurses -pthread

bin/main:$(SRC)
	$(CC) $^ -o $@ $(INFLAGS) $(LDFLAGS)

clean:
	$(RM) bin/main
	