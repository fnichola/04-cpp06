/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:40:18 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/20 03:20:16 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>

class Convert
{
public:
	Convert();
	Convert(const Convert& src);
	Convert(const std::string& str);
	Convert& operator=(const Convert& rhs);
	Convert& operator=(const std::string& str);
	~Convert();

	void printAll() const;

	char getChar() const;
	int getInt() const;
	float getFloat() const;
	double getDouble() const;

	enum conversionError {
		NO_ERROR = 0,
		NON_DISPLAY,
		IMPOSSIBLE,
		OVERFLOW,
		INVALID
	};
	static const std::string getErrorMessage(const conversionError err);

	template <typename T>
	struct ConvertedItem {
		ConvertedItem() : err(NO_ERROR), value(0) {}
		ConvertedItem(T value) : err(NO_ERROR), value(value) {}
		conversionError err;
		T value;
	};

private:
	void strToChar(const std::string& str);
	void strToInt(const std::string& str);
	void strToFloat(const std::string& str);
	void strToDouble(const std::string& str);

	void doConversion(const std::string& str);
	void resetErrors();
	void allErrors(const conversionError err);
	static bool isCharLiteral(const std::string& str);
	static bool isIntLiteral(const std::string& str);
	static bool isFloatLiteral(const std::string& str);
	static bool isDoubleLiteral(const std::string& str);

	ConvertedItem<char> m_char;
	ConvertedItem<int> m_int;
	ConvertedItem<float> m_float;
	ConvertedItem<double> m_double;

	template <typename T>
	void castAllFrom(const ConvertedItem<T>& src)
	{
		m_char.value = static_cast<char>(src.value);
		if (src.value != src.value)
			m_char.err = IMPOSSIBLE;
		else if (static_cast<T>(m_char.value) != src.value)
			m_char.err = OVERFLOW;
		else if (!std::isprint(m_char.value))
			m_char.err = NON_DISPLAY;

		m_int.value = static_cast<int>(src.value);
		if (src.value != src.value)
			m_int.err = IMPOSSIBLE;
		else if (static_cast<T>(m_int.value) != src.value)
			m_int.err = OVERFLOW;

		m_float.value = static_cast<float>(src.value);
		if (src.value != src.value)
			m_float.value = std::numeric_limits<float>::quiet_NaN();
		else if (static_cast<T>(m_float.value) != src.value)
			m_float.err = OVERFLOW;

		m_double.value = static_cast<double>(src.value);
		if (src.value != src.value)
			m_double.value = std::numeric_limits<double>::quiet_NaN();
		else if (static_cast<T>(m_double.value) != src.value)
			m_double.err = OVERFLOW;
	}
};

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<char> item);
std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<int> item);
std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<float> item);
std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<double> item);

#endif
