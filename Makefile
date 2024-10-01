# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 15:02:59 by bbento-a          #+#    #+#              #
#    Updated: 2024/10/01 11:05:25 by bbento-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# VARIABLES
#

# Name of the executable(s)

NAME			= philo

# Directories

SRC_DIR			= src/
OBJ_DIR			= obj/

# Compiler and Flags

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

# Source Files

PHL_SRCS		=	main.c \
					philos_init.c \
					philos_at_table.c \
					philos_activity.c \
					ft_functions.c \
					exit_functions.c

# Conversion of files (Linking and applying pattern substituition to all source files)

SRC             = $(addprefix $(SRC_DIR), $(PHL_SRCS))
OBJ				= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

#
# RULES
#


all:			$(NAME)
				
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:			
				$(RM) -r $(OBJ_DIR)
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

# Phony (It helps avoid conflicts between files named the same)
.PHONY: 		all clean fclean re