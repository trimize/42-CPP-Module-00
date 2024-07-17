/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:29:28 by trimize           #+#    #+#             */
/*   Updated: 2024/04/08 20:01:21 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <limits>

class PhoneBook
{
	private :
		Contact contacts[8];
	public :
		PhoneBook();
		~PhoneBook();
		void	add(int i);
		void	search(int i);
		void	printW(void);
};

#endif