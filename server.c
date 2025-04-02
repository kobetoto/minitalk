/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:51:14 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/02 14:31:52 by thodavid         ###   ########.fr       */
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

void	handler(int	sig)
{
	(void) sig;
	printf("\nhandler serve function\n\n");
}


int	main(void)
{
	/*déclares une structure qui va contenir la configuration du comportement à adopter quand ton programme reçoit un signal (ici SIGUSR1).*/
	struct sigaction sact;

	ft_printf("pid SERV: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	/*sa_handler est un pointeur vers une fonction qui prend un int (le signal reçu) et ne retourne rien (void).*/
	sact.sa_handler = handler;
	sigaction(SIGUSR1, &sact, NULL);

	kill(1654671, SIGUSR1);
	return (0);
}
