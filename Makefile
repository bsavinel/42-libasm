# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 15:16:24 by bsavinel          #+#    #+#              #
#    Updated: 2023/08/17 18:39:03 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm_test

################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	main.c			\
		strlen_test.c	\
		strcpy_test.c	\
		strcmp_test.c	\
		strdup_test.c	\
		write_test.c	\
		read_test.c		\

################################################################################
#                               INCLUDES                             	       #
################################################################################

INCS			=	-I ./includes/		\
					-I ./libasm/includes
					
LIB				=	libasm/libasm.a

################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

SRC_PATH		=	./srcs/
OBJ_PATH		=	./objs/

################################################################################
#                               OUTPUT_FILES                              	   #
################################################################################

OBJS			=	$(addprefix $(OBJ_PATH), ${SRCS:.c=.o})
DEPS			=	${OBJS:.o=.d}

################################################################################
#                                   COLORS                                     #
################################################################################

RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
NO_COLOR		=	\033[m

################################################################################
#                                   RULES                                      #
################################################################################

all	: 
	echo "$(CYAN)"Compilation of $(NAME) in progress... "$(NO_COLOR)"
	make $(NAME) --no-print-directory && echo "$(GREEN)"$(NAME) -- Compilation complete ! "$(NO_COLOR)" || echo "$(RED)"$(NAME) -- Compilation Failed "$(NO_COLOR)"

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(INCS) libasm/libasm.a

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	mkdir -p $(dir $@)
	echo "$(YELLOW)""Compiling $<""$(NO_COLOR)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCS) -c $< -o $@  

clean :
	echo "$(PURPLE)""Cleaning objects and dependence files""$(NO_COLOR)"
	rm -rf $(OBJ_PATH)

fclean : clean
	echo "$(PURPLE)""Cleaning executable""$(NO_COLOR)"
	rm -rf $(NAME)

re : fclean 
	$(MAKE) all --no-print-directory

bonus : all

libasm/libasm.a :
	$(MAKE) -C ./libasm/ --no-print-directory

-include $(DEPS)

.PHONY : all clean fclean re

.SILENT :