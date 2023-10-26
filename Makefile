CC = cc
LDFLAGS = -L./lib/ -lft
CFLAGS = -c -Wall -I./include -I./lib
SOURCE = $(wildcard src/*.c)
OBJ=$(SOURCE:.c=.o)

EXE= ft_printf

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(EXE)
