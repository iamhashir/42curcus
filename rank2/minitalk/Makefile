.PHONY: all clean fclean re server client sclean server_bonus client_bonus bonus
CC=cc
CFLAGS= -Wall -Werror -Wextra 

INC_BONUS=./$(bon)/minitalk_bonus.h
INC_MAN=./$(man)/minitalk.h

bon=bonus
man=mandatory

CFILES = ./$(man)/server.c ./$(man)/client.c ./$(man)/utils.c ./$(bon)/server_bonus.c ./$(bon)/client_bonus.c ./$(bon)/utils_bonus.c
OBJ= $(CFILES:.c=.o)

all:  server client sclean

$(bon): server_bonus client_bonus sclean


server: ./$(man)/server.o ./$(man)/utils.o ./$(INC_MAN)
	$(CC) $(CFLAGS) ./$(man)/server.o ./$(man)/utils.o -o server

client: ./$(man)/client.o ./$(man)/utils.o ./$(INC_MAN)
	$(CC) $(CFLAGS) ./$(man)/client.o ./$(man)/utils.o -o client
 
server_bonus: $(bon)/server_bonus.o $(bon)/utils_bonus.o $(INC_BONUS)
	$(CC) $(CFLAGS) $(bon)/server_bonus.o $(bon)/utils_bonus.o -o server_bonus

client_bonus: $(bon)/client_bonus.o $(bon)/utils_bonus.o $(INC_BONUS)
	$(CC) $(CFLAGS) $(bon)/client_bonus.o $(bon)/utils_bonus.o -o client_bonus

fclean: clean
	rm -f server client server_bonus client_bonus 
clean:
	rm -rf ./$(man)/*.o
	rm -rf ./$(bon)/*.o

re: fclean all

sclean:
	rm -rf ./$(man)/*.o
	rm -rf ./$(bon)/*.o
