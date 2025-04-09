/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Randomizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:10:00 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/09 18:11:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif