/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:34:47 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/06 12:46:59 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 1);
	exit(0);
}

void	check_arg(char *pid, char *msg)
{
	check_pid(pid);
	if (ft_strlen(msg) == 0)
		ft_error("MSG err");
}

int	check_pid(char *msg)
{
	int	i;

	i = 0;
	if (ft_strlen(msg) == 0 || msg[0] == '-')
		ft_error("PID err");
	while (msg[i])
	{
		if (!(msg[i] >= '0' && msg[i] <= '9'))
			ft_error("PID err");
		i++;
	}
	return (1);
}

long	ft_ascii_to_pid(char *str)
{
	int		i;
	int		check;
	long	r;

	i = 0;
	r = 0;
	check = check_pid(str);
	if (!check)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r);
}

char	*char_to_bit(char c)
{
	int		i;
	char	*bit;

	i = 0;
	bit = malloc(9);
	if (bit == NULL)
		return (NULL);
	bit[8] = '\0';
	while (i < 8)
	{
		bit[i] = ((c >> (7 - i)) & 1) + '0';
		i++;
	}
	return (bit);
}
