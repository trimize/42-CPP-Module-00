/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:25:19 by trimize           #+#    #+#             */
/*   Updated: 2024/04/08 23:28:25 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::printW(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}
void	PhoneBook::add(int i)
{
	this->contacts[i % 8].init();
}
void	PhoneBook::search(int i)
{
	int	y = 0;
	int	input = 0;
	bool	end = false;

	while (y < i && y < 8)
	{
		this->contacts[y].searchdisplay(y + 1);
		y++;
	}
	while (!end)
	{
		std::cout << "Enter the contact's index to display : " << std::endl;
		std::cin >> input;
		if (std::cin.good() && input > 0 && input <= 8)
			end = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
			std::cout << "Wrong index, please re-enter : " << std::endl;
		}
	}
	this->contacts[input - 1].display();
}