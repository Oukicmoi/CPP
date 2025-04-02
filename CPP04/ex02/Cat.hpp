/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:18:53 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/01 18:22:01 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain* _brain;
    public:
        Cat();
        virtual ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual void makeSound() const;
};

#endif