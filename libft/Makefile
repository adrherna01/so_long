# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:07:48 by adrherna          #+#    #+#              #
#    Updated: 2024/12/11 16:30:52 by adrherna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS	= -Wall -Werror -Wextra
CFILES	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_check_char.c ft_printf.c ft_put1.c ft_put2.c get_next_line_utils.c get_next_line.c
OBJ		= $(CFILES:.c=.o)
bonus	= ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c
OBJ2	= $(bonus:.c=.o)
CC		= cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus:$(OBJ) $(OBJ2)
	ar -rcs $(NAME) $(OBJ2)

fclean:clean
	rm -f $(NAME)

re: fclean all

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
