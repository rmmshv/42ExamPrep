/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resheva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:45:10 by resheva           #+#    #+#             */
/*   Updated: 2019/01/29 22:05:36 by resheva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Write a program that takes a string and displays it, replacing each of its letters by the letter 13 spaces ahead in alphabetical order.

 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

 The output will be followed by newline.

 If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

int		main(int ac, char **av)
{
	int	i;
	char mvup;
	char mvdwn;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			mvup = av[1][i] + 13;
			mvdwn = av[1][i] - 13;
			if (('A' <= av[1][i] && 'M' >= av[1][i])
				|| ('a' <= av[1][i] && 'm' >= av[1][i]))
				write(1, &mvup, 1);
			else if (('N' <= av[1][i] && 'Z' >= av[1][i])
					|| ('n' <= av[1][i] && 'z' >= av[1][i]))
				write(1, &mvdwn, 1);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
