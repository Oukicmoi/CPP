/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:54:19 by gtraiman          #+#    #+#             */
/*   Updated: 2025/01/30 20:11:15 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;
	if(ac == 1)
		return(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while(av[i])
	{
		if(i != 1)
			std::cout << " ";
		while(av[i][j])
		{
			char c = av[i][j];
			c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
			std::cout << c;
			std::cout.flush();
			j++;
		}
		i++;
		j = 0;
	}
	std::cout << std::endl;
	return(0);
}