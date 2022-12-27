/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/27 06:30:14 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "debugPrint.hpp"


int main()
{
	std::srand(std::time(0));

	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	debugPrint("Identify by pointer:");
	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
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

	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	debugPrint("Identify by reference:");
	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

	Base base2;
	A a2;
	B b2;
	C c2;
	identify(base2);
	identify(a2);
	identify(b2);
	identify(c2);

	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	debugPrint("Generate random objects:");
	debugPrint("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");


	for (int i = 0; i < 10; ++i)
	{
		Base *p = generate();
		identify(p);
		identify(*p);
		delete p;
		debugPrint("------------------------------------------");
	}

	return 0;
}
