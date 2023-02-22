
CC = gcc
CRTFLAGS = -lcriterion
SDLFLAGS = -lSDL2_image -lSDL2 -lSDL2_ttf
CFLAGS = -std=c99 -Wall
LDFLAGS = -fsanitize=address -g3

SRC = $(shell find src/ -name "*.c" ! -name main.c)
TEST = $(shell find tests/ -name "*.c")

all: main check

main: $(SRC) src/main.c
	$(CC) $(CFLAGS) -Ofast -o $@ $^ $(SDLFLAGS)

debug: $(SRC) src/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(SDLFLAGS)

check: $(SRC) $(TEST)
	$(CC) $(CFLAGS) $(LDFLAGS) -Ofast -o $@ $^ $(SDLFLAGS) $(CRTFLAGS)

clean:
	$(RM) main debug check clean

.PHONY: main debug check clean
