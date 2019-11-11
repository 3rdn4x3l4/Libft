# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 13:09:47 by alagache          #+#    #+#              #
#    Updated: 2019/11/04 16:30:01 by alagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

#Lib sources
SRCS= ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memalloc.c\
	  ft_memjoin.c\
	  ft_memdel.c\
	  ft_strlen.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isprint.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isalpha.c\
	  ft_isalnum.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_itoa_base.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_2lstadd_first.c\
	  ft_2lstadd_last.c\
	  ft_2lstdel.c\
	  ft_2lstdelone.c\
	  ft_2lstdelnext.c\
	  ft_2lstnew.c\

#GNL sources
SRCS += get_next_line.c\

#Printf sources
SRCS += ft_printf.c\
	  ft_dprintf.c\
	  pwidth.c\
	  pflags.c\
	  pwidth.c\
	  plenmodifier.c\
	  pprecision.c\
	  func_selector.c\
	  global_tools.c\
	  int.c\
	  int_tools.c\
	  unsigned.c\
	  unsigned_tools.c\
	  octal.c\
	  octal_tools.c\
	  percent.c\
	  char.c\
	  hexa.c\
	  hexa_tools.c\
	  hexa_upper.c\
	  string.c\
	  float.c\
	  float_tools.c\
	  double.c\
	  double_tools.c\
	  ldouble.c\
	  ldouble_tools.c\
	  address_tools.c\
	  address.c\
	  special.c\
	  special_tools.c\

CFLAGS= -Wall -Werror -Wextra

HEADERPATH= includes

OBJDIR= obj

OBJ= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)
		echo "lib builded"

obj/%.o : srcs/%.c
	mkdir -p $(OBJDIR)
	gcc $(CFLAGS) -I $(HEADERPATH) -o $@ -c $<

clean:
		rm -rf $(OBJDIR)
		echo "lib objects cleaned"

fclean: clean
		rm -f $(NAME)
		echo "lib cleaned"

re: fclean all

.PHONY: clean all fclean re 
.SILENT: clean all fclean re $(OBJ) $(NAME)
