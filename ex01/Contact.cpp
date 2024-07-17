/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:46:49 by trimize           #+#    #+#             */
/*   Updated: 2024/04/08 20:09:54 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getinput(std::string str) const
{
	bool	end = false;
	std::string input = "";
	while (!end)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			end = true;
		else
		{
			std::cin.clear();
			std::cout << "Nope try again" << std::endl;
		}
	}
	return (input);
}

void	Contact::init(void)
{
	std::cin.ignore();
	this->firstname = this->getinput("Please enter the first name : ");
	this->lastname = this->getinput("Please enter the last name : ");
	this->nickname = this->getinput("Please enter the nickname : ");
	this->phonenumber = this->getinput("Please enter the phone number : ");
	this->darkestsecret = this->getinput("Please enter the contact's darkest secret : ");
}

void	Contact::display(void)
{
	std::cout << "First name : " << this->firstname << std::endl;
	std::cout << "Last name : " << this->lastname << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phonenumber << std::endl;
	std::cout << "Darkest secret : " << this->darkestsecret << std::endl;
}

void	Contact::searchdisplay(int index)
{
	std::cout << "|" << std::setw(10) << index;
	if (this->firstname.length() > 10)
		this->firstname = this->firstname.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << this->firstname;
	if (this->lastname.length() > 10)
		this->lastname = this->lastname.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << this->lastname;
	if (this->nickname.length() > 10)
		this->nickname = this->nickname.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << this->nickname << "|" << std::endl;
	
}
