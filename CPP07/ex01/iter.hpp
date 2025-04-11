/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:32:07 by gtraiman          #+#    #+#             */
/*   Updated: 2025/04/11 18:00:16 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, size_t length, void func(T &))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void multiplyByTwo(T &x)
{
    x *= 2;
}

template <typename T>
void plusone(T &x)
{
    x = "hello";
}

#endif