NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_SRC = client.c 
SERVER_SRC = server.c 
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_PATH=ft_printf
FT_PRINTF=$(FT_PRINTF_PATH)/libftprintf.a
FT_PRINTF_LIB_FLAGS=-L $(FT_PRINTF_PATH) -lftprintf -I $(FT_PRINTF_PATH)


all: $(NAME)  

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(FT_PRINTF) $(CLIENT_SRC)
	@$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT) $(FT_PRINTF_LIB_FLAGS)

$(SERVER): $(FT_PRINTF) $(SERVER_SRC) 
	@$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER) $(FT_PRINTF_LIB_FLAGS)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_PATH)

clean:
	$(RM) $(CLIENT) $(SERVER)
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re