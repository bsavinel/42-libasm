# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 14:54:40 by bsavinel          #+#    #+#              #
#    Updated: 2023/10/23 11:08:34 by bsavinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

AS			= nasm
ASFLAGS		= -f elf64

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	ft_read.s		\
		ft_strcmp.s		\
		ft_strcpy.s		\
		ft_strdup.s		\
		ft_strlen.s		\
		ft_write.s		\

################################################################################
#                               INCLUDES                             	       #
################################################################################

INCS			=	-I ./includes/

################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

SRC_PATH		=	./srcs/
OBJ_PATH		=	./objs/

################################################################################
#                               OUTPUT_FILES                              	   #
################################################################################

OBJS			=	$(addprefix $(OBJ_PATH), ${SRCS:.s=.o})
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

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o : $(SRC_PATH)%.s
	mkdir -p $(dir $@)
	echo "$(YELLOW)""Compiling $<""$(NO_COLOR)"
	$(AS) $(ASFLAGS) $< -o $@ $(INCS)

clean :
	echo "$(PURPLE)""Cleaning objects and dependence files""$(NO_COLOR)"
	rm -rf $(OBJ_PATH)

fclean : clean
	echo "$(PURPLE)""Cleaning librarie""$(NO_COLOR)"
	rm -rf $(NAME)

re : fclean 
	make all --no-print-directory

bonus : all

-include $(DEPS)

.PHONY : all clean fclean re

.SILENT: