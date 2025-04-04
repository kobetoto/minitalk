/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:14:02 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/04 10:27:18 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include "./ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>

void ft_putendl_fd(char *s, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putchar_fd(char c, int fd);
int check_pid(char *msg);
int ft_strlen(char *str);
char *char_to_bit(char c);
long ft_ascii_to_pid(char *str);
void ft_error(char *str);
void handler(int sig);
void check_arg(char *msg, char *pid);


#endif
