
CC = gcc
CFLAGS = -std=c99 -Wall
LDFLAGS = -fsanitize=address -g3
CRTFLAGS = -lcriterion

SRC = $(shell find src/ -name "*.c" ! -name main.c)
TEST = $(shell find tests/ -name "*.c")

all: main check

main: $(SRC) src/main.c
	echo ${TEST}
	$(CC) $(CFLAGS) -Ofast -o $@ $^

debug: $(SRC) src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

check: $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(LDFLAGS) -Ofast -o $@ $^ $(CRTFLAGS)

clean:
	$(RM) main debug check clean

.PHONY: main debug check clean
