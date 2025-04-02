/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:30 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/02 17:53:12 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
██████  ██      ██ ███████ ███    ██ ████████
██      ██      ██ ██      ████   ██    ██
██      ██      ██ █████   ██ ██  ██    ██
██      ██      ██ ██      ██  ██ ██    ██
██████  ███████ ██ ███████ ██   ████    ██
*/

#include "minitalk.h"

void handler(int sig)
{
	(void)sig;
	printf("\nhandler serve function\n\n");
}

// !!!! free si besoin le return de print bit
char *char_to_bit(char c)
{
	int	i;
	char *bit;

	i = 8;
	bit = malloc(9);
	if (bit == NULL)
		return (NULL);
	bit[8] = '\0';
	while (i--)
		bit[i] = (c >> i & 1) + '0';
	return (bit);
}

long	ft_ascii_to_pid(const char *str)
{
	int			i;
	long		r;
//!!!!!!!!!!!!!!!!! attention verification si chaine vide si caratere alphabetique!!!!!!!!!!!!!!
	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r);
}

int main(int ac, char **av)
{
	pid_t	pid;
	if (ac != 3)
		return (0);
	/*
	1- WRITE PID
	2- CHECK MESSAGE
	3- DECOMPOSER MESSAGE
	4- ENVOIE MESSAGE BIT/BIT
	*/
	pid = (pid_t)ft_ascii_to_pid(av[1]);
	ft_printf("pid CLI: %d\n", getpid());
}
