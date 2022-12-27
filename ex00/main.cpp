/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/27 03:42:26 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "Convert.hpp"
#include "debugPrint.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Convert(argv[1]).printAll();
		return 0;
	}

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
	Convert("0").printAll();
	debugPrint("------------------------------------------");
	Convert("-0").printAll();
	debugPrint("------------------------------------------");
	Convert("-42").printAll();
	debugPrint("------------------------------------------");
	Convert("2147483647").printAll();
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

	debugPrint("Default Constructor: Convert a; a = \"123\"");
	Convert a;
	a = "123";
	a.printAll();
	debugPrint("------------------------------------------");
	debugPrint("Assignment operator: b = a");
	Convert b = a;
	b.printAll();
	debugPrint("------------------------------------------");
	debugPrint("Assignment b = \"9999999999999\"");
	b = "9999999999999";
	b.printAll();
	debugPrint("------------------------------------------");
	debugPrint("Assignment b = \"b\"");
	b = "b";
	b.printAll();
	debugPrint("------------------------------------------");
	return 0;
}
