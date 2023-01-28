# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagache <alagache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 13:09:47 by alagache          #+#    #+#              #
#    Updated: 2020/06/28 19:17:27 by alagache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang

CFLAGS= -Wall -Werror -Wextra
#Only one line at a time
# CFLAGS+= -g3 -fsanitize=address,leak,undefined -fno-omit-frame-pointer 
# CFLAGS+= -g3 -fsanitize=thread,undefined
# CFLAGS+= -g3 -fsanitize=memory,undefined

NAME= libft.a

SRCDIR = srcs

#MEM* sources
LIBSRCS = ft_memset.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memalloc.c\
	  ft_memjoin.c\
	  ft_memdel.c\
	  ft_bzero.c\
	  ft_free_arr.c\

#STR* sources
LIBSRCS += ft_strlen.c\
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
	  ft_strjoinfree.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_ischarset.c\
	  ft_occurence_of.c\

#IS* sources
LIBSRCS += ft_isprint.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isalpha.c\
	  ft_isalnum.c\

#TO* sources
LIBSRCS += ft_atoi.c\
	  ft_itoa.c\
	  ft_itoa_base.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_atol.c\

#PUT* sources
LIBSRCS += ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\

#LST* sources
LIBSRCS += ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\

#2LST* sources
LIBSRCS += ft_2lstadd_first.c\
	  ft_2lstadd_last.c\
	  ft_2lstdel.c\
	  ft_2lstdelone.c\
	  ft_2lstdelnext.c\
	  ft_2lstnew.c\

#GNL sources
GNLSRCS += get_next_line.c\

#Printf sources
PRINTFSRCS += ft_printf.c\
	  ft_dprintf.c\
	  pwidth.c\
	  pflags.c\
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

OBJDIR= obj

LIBOBJ= $(addprefix $(OBJDIR)/lib/,$(LIBSRCS:.c=.o))
GNLOBJ= $(addprefix $(OBJDIR)/gnl/,$(GNLSRCS:.c=.o))
PRINTFOBJ= $(addprefix $(OBJDIR)/printf/,$(PRINTFSRCS:.c=.o))

HEADDIR = includes

LIBHEAD = $(HEADDIR)/libft.h
GNLHEAD = $(HEADDIR)/get_next_line.h
PRINTFHEAD = $(HEADDIR)/arg.h $(HEADDIR)/ft_printf.h

#Print colors/lneclr
BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"
YELLOW = "\\033[33m"
PURPLE = "\\033[35m"
LNECLR = "\\33[2K\\r"

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBOBJ) $(GNLOBJ) $(PRINTFOBJ)
	$(AR) rcs $(NAME) $^
	sed -e '1s/^/[\n/' -e '$$s/,$$/\n]/' $(OBJDIR)/*/*.json > compile_commands.json
	printf "$(LNECLR)$(GREEN)make libft done$(WHITE)\n"

$(OBJDIR):
	mkdir -p $(OBJDIR)/lib
	mkdir -p $(OBJDIR)/gnl
	mkdir -p $(OBJDIR)/printf

$(OBJDIR)/printf/%.o: $(SRCDIR)/printf/%.c $(PRINTFHEAD) $(LIBHEAD)
	$(CC) -MJ $@.json $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<$(WHITE)"

$(OBJDIR)/gnl/%.o: $(SRCDIR)/gnl/%.c $(GNLHEAD) $(LIBHEAD)
	$(CC) -MJ $@.json $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<"$(WHITE)

$(OBJDIR)/lib/%.o: $(SRCDIR)/lib/%.c $(LIBHEAD)
	$(CC) -MJ $@.json $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<"$(WHITE)

clean:
	$(RM) -rf $(OBJDIR)
	printf "$(PURPLE)clean libft done$(WHITE)\n"

fclean:
	$(RM) -rf $(OBJDIR) $(NAME)
	printf "$(RED)fclean libft done$(WHITE)\n"

re:
	$(MAKE) -s fclean
	$(MAKE) -s all
	printf "$(BLUE)re libft done$(WHITE)\n"

.PHONY: clean all fclean re 
.SILENT: clean fclean re $(OBJDIR) $(LIBOBJ) $(PRINTFOBJ) $(GNLOBJ) $(NAME)
