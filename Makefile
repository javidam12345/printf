CC = cc
CFLAGS = -c -Wall -I./include
SOURCE = main.c ft_printf.c
OBJ=$(SOURCE:.c=.o)

EXE= ft_printf

all: $(SOURCE) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@


%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(EXE)
