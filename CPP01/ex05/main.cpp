/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:10:30 by gtraiman          #+#    #+#             */
/*   Updated: 2025/03/23 16:35:58 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"



int main()
{
    Harl Harl;
    
    Harl.complain("INFO");
    Harl.complain("DEBUG");
    Harl.complain("ERROR");
    Harl.complain("WARNING");
}