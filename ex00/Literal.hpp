/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:04:42 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/19 03:05:23 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

#include <string>

class Convert
{
public:
	Convert();
	Convert(const Convert& src);
	Convert& operator=(const Convert& rhs);
	~Convert();

	enum conversionError {
		NO_ERROR = 0,
		NON_DISPLAY,
		IMPOSSIBLE
	};

	void doConversion(const std::string& str);
	static const std::string getErrorMessage(const conversionError err);

	template <typename T>
	struct ConvertedItem {
		ConvertedItem() : err(NO_ERROR) {}
		conversionError err;
		T value;
	};

private:
	char strToChar(const std::string& str);
	int strToInt(const std::string& str);
	float strToFloat(const std::string& str);
	double strToDouble(const std::string& str);

	void printAll() const;
	static bool isIntLiteral(const std::string& str);

	ConvertedItem<char> m_char;
	ConvertedItem<int> m_int;
	ConvertedItem<float> m_float;
	ConvertedItem<double> m_double;

	template <typename T>
	void castAll(const T& val)
	{
		m_char.value = static_cast<char>(val);
		if (!std::isprint(m_char.value))
			m_char.err = NON_DISPLAY;

		m_int.value = static_cast<int>(val);
		m_float.value = static_cast<float>(val);
		m_double.value = static_cast<double>(val);
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<T> item)
{
	if (item.err)
		os << Convert::getErrorMessage(item.err);
	else
		os << item.value;
	return os;
}

std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<float> item);
std::ostream& operator<<(std::ostream& os, Convert::ConvertedItem<double> item);

#endif
