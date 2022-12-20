/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:42:18 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/20 03:22:01 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <exception>
#include <sstream>
#include <limits>
#include "Convert.hpp"


Convert::Convert() {}

Convert::Convert(const Convert& src)
{
	*this = src;
}

Convert::Convert(const std::string& str)
{
	doConversion(str);
}

Convert& Convert::operator=(const Convert& rhs)
{
	m_char = rhs.m_char;
	m_int = rhs.m_int;
	m_float = rhs.m_float;
	m_double = rhs.m_double;
	return *this;
}

Convert& Convert::operator=(const std::string& str)
{
	doConversion(str);
	return *this;
}

Convert::~Convert() {}

void Convert::doConversion(const std::string& str)
{
	resetErrors();
	if (isCharLiteral(str))
	{
		strToChar(str);
		castAllFrom<char>(m_char);
	}
	else if (isIntLiteral(str))
	{
		strToInt(str);
		castAllFrom<int>(m_int);
	}
	else if (isFloatLiteral(str))
	{
		strToFloat(str);
		castAllFrom<float>(m_float);
	}
	else if (isDoubleLiteral(str))
	{
		strToDouble(str);
		castAllFrom<double>(m_double);
	}
	else
		allErrors(INVALID);
}

void Convert::resetErrors()
{
	m_char.err = NO_ERROR;
	m_int.err = NO_ERROR;
	m_float.err = NO_ERROR;
	m_double.err = NO_ERROR;
}

void Convert::allErrors(const conversionError err)
{
	m_char.err = err;
	m_int.err = err;
	m_float.err = err;
	m_double.err = err;
}

void Convert::strToChar(const std::string& str)
{
	m_char.value = str.c_str()[0];
}

void Convert::strToInt(const std::string& str)
{
	std::stringstream ss;
	ss << str;
	int num;
	ss >> num;
	if (ss.fail())
		std::cerr << "[Warning!] Conversion to int overflowed" << std::endl;
	m_int.value = num;
}

void Convert::strToFloat(const std::string& str)
{
	if (str == "-inff")
		m_float.value = -std::numeric_limits<float>::infinity();
	else if (str == "+inff")
		m_float.value = std::numeric_limits<float>::infinity();
	else if (str == "nanf")
		m_float.value = std::numeric_limits<float>::quiet_NaN();
	else
	{
		std::stringstream ss;
		ss << str;
		float num;
		ss >> num;
		if (ss.fail())
			std::cerr << "[Warning!] Conversion to float overflowed" << std::endl;
		m_float.value = num;
	}
}

void Convert::strToDouble(const std::string& str)
{
	if (str == "-inf")
		m_double.value = -std::numeric_limits<double>::infinity();
	else if (str == "+inf")
		m_double.value = std::numeric_limits<double>::infinity();
	else if (str == "nan")
		m_double.value = std::numeric_limits<double>::quiet_NaN();
	else
	{
		std::stringstream ss;
		ss << str;
		double num;
		ss >> num;
		if (ss.fail())
			std::cerr << "[Warning!] Conversion to double overflowed" << std::endl;
		m_double.value = num;
	}
}

bool Convert::isCharLiteral(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool Convert::isIntLiteral(const std::string& str)
{
	if (str.empty())
		return false;

	std::string::const_iterator it = str.begin();
	if (*it != '+' && *it != '-' && !std::isdigit(*it))
		return false;
	++it;
	while (it != str.end())
	{
		if (!std::isdigit(*it))
			return false;
		++it;
	}
	return true;
}

bool Convert::isFloatLiteral(const std::string& str)
{
	// minimum size is 3 digits (e.g. "0.f")
	if (str.length() < 3)
		return false;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	
	// for our purposes a float literal must end with 'f', with no trailing
	// characters
	if (str.at(str.length() - 1) != 'f')
		return false;

	// the float literal must start with '+', '-', or a digit
	std::string::const_iterator it = str.begin();
	if (*it != '+' && *it != '-' && !std::isdigit(*it))
		return false;

	++it;
	// only digits to the left of the decimal point
	while (it != str.end())
	{
		if (*it == '.')
			break;
		if (!std::isdigit(*it))
			return false;
		++it;
	}

	// reached end of string without finding a decimal point
	if (it == str.end())
		return false;

	++it;
	// only digits and a final f to the right of the decimal point
	while (it != str.end() - 1)
	{
		if (!std::isdigit(*it))
				return false;
		++it;
	}
	return true;
}

bool Convert::isDoubleLiteral(const std::string& str)
{
	// minimum size is 2 digits (e.g. "0.")
	if (str.length() < 2)
		return false;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;

	// the double literal must start with '+', '-', or a digit
	std::string::const_iterator it = str.begin();
	if (*it != '+' && *it != '-' && !std::isdigit(*it))
		return false;

	++it;
	// only digits to the left of the decimal point
	while (it != str.end())
	{
		if (*it == '.')
			break;
		if (!std::isdigit(*it))
			return false;
		++it;
	}

	// reached end of string without finding a decimal point
	if (it == str.end())
		return false;

	++it;
	// only digits to the right of the decimal point
	while (it != str.end())
	{
		if (!std::isdigit(*it))
				return false;
		++it;
	}
	return true;
}

void Convert::printAll() const
{
	std::cout << "char: " << m_char << std::endl;
	std::cout << "int: " << m_int << std::endl;
	std::cout << "float: " << m_float << std::endl;
	std::cout << "double: " << m_double << std::endl;
}

const std::string Convert::getErrorMessage(const conversionError err)
{
	switch(err) 
	{
		case NO_ERROR:
			return "";
		case NON_DISPLAY:
			return "non displayable";
		case IMPOSSIBLE:
			return "impossible";
		case OVERFLOW:
			return "overflow";
		case INVALID:
			return "invalid";
		default:
			return "unknown error";
	}
}

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<char> item)
{
	if (item.err)
		os << Convert::getErrorMessage(item.err);
	else
		os << "'" << item.value << "'";
	return os;
}

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<int> item)
{
	if (item.err)
		os << Convert::getErrorMessage(item.err);
	else
		os << item.value;
	return os;
}

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<float> item)
{
	if (item.err)
		os << Convert::getErrorMessage(item.err);
	else if (static_cast<int>(item.value) == item.value)
		os << item.value << ".0f";
	else
		os << item.value;
	return os;
}

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<double> item)
{
	if (item.err)
		os << Convert::getErrorMessage(item.err);
	else if (static_cast<int>(item.value) == item.value)
		os << item.value << ".0";
	else
		os << item.value;
	return os;
}
