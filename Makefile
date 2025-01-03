SERVER = server
CLIENT = client
SRVSRC = server.c ft_printf.c
CLISRC = client.c ft_printf.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) $(SRVSRC) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) $(CLISRC) -o $(CLIENT)

clean:
	rm -f server.o client.o ft_printf.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all