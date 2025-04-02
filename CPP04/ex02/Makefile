# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 19:37:44 by gtraiman          #+#    #+#              #
#    Updated: 2025/03/31 21:37:40 by gtraiman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Animal

CXX         = c++

CXXFLAGS    = -std=c++98 -Wall -Wextra -Werror -g3

SRCS        = 	Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				Brain.cpp \
				main.cpp \

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
