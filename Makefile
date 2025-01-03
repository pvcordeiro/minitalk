SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c server.c libft.c
OBJS = $(SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(SERVER)

$(CLIENT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(CLIENT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all