CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Werror -O2
LDFLAGS = 
SRC = src/colorsort.c src/stack.c src/datatypes.c
OBJ = $(SRC:.c=.o)
BIN = bin/colorsort

all: $(BIN)

bin:
	@mkdir -p bin

$(BIN): bin $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

run: all
	./$(BIN)

clean:
	rm -rf bin $(OBJ)

test: all
	./$(BIN) < tests/sample_input.txt || true

.PHONY: all run clean test
