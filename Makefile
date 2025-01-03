SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRCSRV:.c=.o) $(SRCCLI:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all