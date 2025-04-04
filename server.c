/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:51:14 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/04 15:07:39 by thodavid         ###   ########.fr       */
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

void handler(int sig)
{
	(void)sig;
	ft_printf("\nhandler serve function\n\n");
}

c handle_siguser(int sig)
{
	if (sig == SIGUSR1)
	{
		
		printf("\nbits is ==1==\n");
	}
	if	(sig == SIGUSR2)
	{
		
		printf("\nbits is ==0==\n");
	}
}

int main(void)
{
	struct sigaction sa;
	
	sa.sa_handler = &handle_siguser;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID SERV: %d\n", getpid());
	while (1)
	{
		sleep(2);
		ft_printf("SERVER ACTIVE...");
	}
	

	return (0);
}

