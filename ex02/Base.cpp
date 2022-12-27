/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 05:18:30 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/27 06:26:30 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base* generate()
{
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "Generated: A" << std::endl;
		return new A;
		break;
	case 1:
		std::cout << "Generated: B" << std::endl;
		return new B;
		break;
	case 2:
		std::cout << "Generated: C" << std::endl;
		return new C;
		break;
	default:
		std::cerr << "Error!: Bad random number." << std::endl;
		break;
	}
	return NULL;
}

void identify(Base* p)
{
	std::cout << "Type = ";
	if (!p)
		std::cout << "NULL";
	else if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Base";
	std::cout << std::endl;
}

template<typename T>
bool tryCast(Base& p)
{
	try
	{
		dynamic_cast<T&>(p);
		return true;
	}
	catch (std::exception& e)
	{
		return false;
	}
}

void identify(Base& p)
{
	std::cout << "Type = ";
	if (tryCast<A>(p))
		std::cout << "A";
	else if (tryCast<B>(p))
		std::cout << "B";
	else if (tryCast<C>(p))
		std::cout << "C";
	else
		std::cout << "Base";
	std::cout << std::endl;
}
