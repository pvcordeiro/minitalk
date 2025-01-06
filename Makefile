SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCSRV = server.c
SRCCLI = client.c
OBJSRV = $(SRCSRV:.c=.o)
OBJCLI = $(SRCCLI:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJSRV)
	$(CC) $(CFLAGS) $(OBJSRV) -o $(SERVER)

$(CLIENT): $(OBJCLI)
	$(CC) $(CFLAGS) $(OBJCLI) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJSRV) $(OBJCLI)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
