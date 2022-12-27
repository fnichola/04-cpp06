/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugPrint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:15:24 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/12 05:40:08 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debugPrint.hpp"

void debugPrint(const std::string& str, const std::string& color)
{
	std::cout << color + str + COLOR_RESET << std::endl;
}
