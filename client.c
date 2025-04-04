/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:30 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/04 14:56:48 by thodavid         ###   ########.fr       */
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
	ft_printf("\nhandler serve function\n\n");
}

void	ft_sending_bit(pid_t pid_serv, char	*msg)
{
	int	i;
	int	j;
	char *bit;

	i = 0;
	while(msg[i])
	{
		bit = char_to_bit(msg[i]);
		if(bit == NULL)
			ft_error("MALLOC err");
		j = 0;
		while(bit[j])
		{
			if(bit[j] == '1')
			{
				kill(pid_serv, SIGUSR1);
				ft_printf("\n==1==\n");
				sleep(1);
			}
			else
			{
				kill(pid_serv, SIGUSR2);
				ft_printf("\n==0==\n");
				sleep(1);
			}
			j++;
		}
		free(bit);
		i++;
	}
	
}

/*parsing des param (PID SERV + MSG)*/
/*
1- PARSING
3- DECOMPOSER MESSAGE
4- ENVOIE MESSAGE BIT/BIT
*/
int main(int ac, char **av)
{
	int	i;
	pid_t	pid_serv;
	
	i = 0;
	/*1-PARSING*/
	if (ac != 3)
	{
		ft_error("ARGs err");
		return (0);
	}
	check_arg(av[1], av[2]);
	pid_serv = (pid_t)ft_ascii_to_pid(av[1]);
	/******************/
	/*SENDING*/
	ft_sending_bit(pid_serv, av[2]);
	/******************/

	ft_printf("PID SERV: %d\n", pid_serv);
	ft_printf("PID CLI: %d\n", getpid());
	ft_printf("message ==%s==\n", av[2]);
}

