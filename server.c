/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:51:14 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/06 12:23:47 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
███████ ███████ ██████  ██    ██ ███████ ██████
██      ██      ██   ██ ██    ██ ██      ██   ██
███████ █████   ██████  ██    ██ █████   ██████
     ██ ██      ██   ██  ██  ██  ██      ██   ██
███████ ███████ ██   ██   ████   ███████ ██   ██
*/

#include "minitalk.h"

void	handle_siguser(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_siguser;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID SERV: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
