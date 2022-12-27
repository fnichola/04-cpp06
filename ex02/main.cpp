/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/27 06:06:28 by fnichola         ###   ########.fr       */
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
#include "debugPrint.hpp"

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

void identify(Base& p)
{
	std::cout << "Type = ";
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		std::cout << "Base" << std::endl;
		return;
	}
}

int main()
{
	std::srand(std::time(0));

	debugPrint("------------------------------------------");
	debugPrint("Identify by pointer:");
	Base* base = new Base;
	Base* a = new A;
	Base* b = new B;
	Base* c = new C;

	identify(base);
	identify(a);
	identify(b);
	identify(c);

	delete base;
	delete a;
	delete b;
	delete c;

	debugPrint("------------------------------------------");
	debugPrint("Identify by reference:");

	Base base2;
	A a2;
	B b2;
	C c2;
	identify(base2);
	identify(a2);
	identify(b2);
	identify(c2);

	debugPrint("------------------------------------------");
	debugPrint("Generate random objects:");

	for (int i = 0; i < 10; ++i)
	{
		Base *p = generate();
		identify(p);
		delete p;
		debugPrint("------------------------------------------");
	}

	return 0;
}
