/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/20 03:08:51 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Convert.hpp"
#include "debugPrint.hpp"


#include <sstream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Convert("c").printAll();
	debugPrint("------------------------------------------");
	Convert("a").printAll();
	debugPrint("------------------------------------------");
	Convert("!").printAll();
	debugPrint("------------------------------------------");
	Convert("abc").printAll();
	debugPrint("------------------------------------------");
	Convert("123").printAll();
	debugPrint("------------------------------------------");
	Convert("9007199254740993.0").printAll();
	debugPrint("------------------------------------------");
	Convert("9007199254740993").printAll();
	debugPrint("------------------------------------------");
	Convert("-inff").printAll();
	debugPrint("------------------------------------------");
	Convert("+inff").printAll();
	debugPrint("------------------------------------------");
	Convert("nanf").printAll();
	debugPrint("------------------------------------------");
	Convert("-inf").printAll();
	debugPrint("------------------------------------------");
	Convert("+inf").printAll();
	debugPrint("------------------------------------------");
	Convert("nan").printAll();
	debugPrint("------------------------------------------");

	// converter.doConversion("0");
	// converter.doConversion("1");
	// converter.doConversion("-1");
	// converter.doConversion("-42");

	std::string s = "-123.f";
	std::stringstream ss;
	ss << s;
	int x;
	ss >> x;
	std::cout << x << std::endl;
	if (ss.fail())
		std::cout << "failed" << std::endl;
	
	float f = std::numeric_limits<float>::infinity();
	std::cout << f << std::endl;
	
	return 0;

}
