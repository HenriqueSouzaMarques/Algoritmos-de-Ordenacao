CC = gcc
FLAGS = -g -Wall -Werror

OBJS = main.o sorts.o utils.o
BIN = main

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(FLAGS) $(OBJS) && rm $(OBJS)

main.o: main.c utils/utils.h sorts/sorts.h
	$(CC) -c $(FLAGS) main.c

sorts.o: sorts/sorts.c
	$(CC) -c $(FLAGS) sorts/sorts.c

utils.o: utils/utils.c
	$(CC) -c $(FLAGS) utils/utils.c

clean:
	rm $(OBJS)