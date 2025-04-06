/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:02:30 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/06 12:47:30 by thodavid         ###   ########.fr       */
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

volatile sig_atomic_t	g_ack_conf = 0;

void	handle_siguser(int sig)
{
	(void) sig;
	g_ack_conf = 1;
}

void	ft_sending_bit(pid_t pid_serv, char *msg)
{
	int			i;
	int			j;
	char		*bit;

	i = 0;
	while (i <= ft_strlen(msg))
	{
		bit = char_to_bit(msg[i]);
		if (bit == NULL)
			ft_error("MALLOC err");
		j = 0;
		while (bit[j])
		{
			g_ack_conf = 0;
			if (bit[j] == '1')
				kill(pid_serv, SIGUSR1);
			else
				kill(pid_serv, SIGUSR2);
			while (!g_ack_conf)
				usleep(50);
			j++;
		}
		free(bit);
		i++;
	}
}

/*parsing des param (PID SERV + MSG)*/
/*
   1- PARSING (check arg + translate the pid param)
   3- DECOMPOSER MESSAGE
   4- ENVOIE MESSAGE BIT/BIT
*/
int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid_serv;
	int					i;

	i = 0;
	if (ac != 3)
	{
		ft_error("ARGs err");
		return (0);
	}
	check_arg(av[1], av[2]);
	pid_serv = (pid_t)ft_ascii_to_pid(av[1]);
	sa.sa_handler = &handle_siguser;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	ft_sending_bit(pid_serv, av[2]);
	return (0);
}
