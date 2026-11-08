CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic

.PHONY: all clean test

all: chess

chess: main.o board.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

test_board: test_board.o board.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o board.o test_board.o: board.h

test: chess test_board
	./test_board
	@output=$$(mktemp) || exit 1; \
	trap '$(RM) "$$output"' 0; \
	./chess > "$$output" && diff -u expected_board.txt "$$output"

clean:
	$(RM) chess test_board main.o board.o test_board.o
