CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = Colleen Grace Sully

SRC = Colleen.c Grace.c Sully.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%: %.o
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f Sully_[0-9]* Grace_kid.c tmp_Colleen a.out

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PRECIOUS: $(OBJ)
.PHONY: all clean fclean re