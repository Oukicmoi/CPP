# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 23:00:32 by gtraiman          #+#    #+#              #
#    Updated: 2025/03/21 23:01:03 by gtraiman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Weapon

CXX         = c++

CXXFLAGS    = -std=c++98 -Wall -Wextra -Werror -g3

SRCS        = 	main.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp \

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
