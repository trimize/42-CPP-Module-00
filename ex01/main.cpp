/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:53:52 by trimize           #+#    #+#             */
/*   Updated: 2024/04/08 20:04:24 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook pb;
	int	i;
	std::string str = "";

	pb.printW();
	i = 0;
	while (str.compare("EXIT"))
	{
		if (str.compare("ADD") == 0)
			pb.add(i++);
		else if(str.compare("SEARCH") == 0)
			pb.search(i);
		std::cin >> str;
	}
	return (0);
}
