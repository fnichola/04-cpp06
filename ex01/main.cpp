/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/27 03:45:45 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "debugPrint.hpp"
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main()
{
	Data data;
	data.name = "Ford Prefect";
	data.occupation = "Freelance writer";
	data.age = 42;

	uintptr_t ip = serialize(&data);
	std::cout << ip << std::endl;
	std::cout << &data << std::endl;
	std::cout << "0x" << std::hex << ip << std::endl;

	Data* newPointer = deserialize(ip);
	std::cout << newPointer->name << std::endl;

	return 0;
}
