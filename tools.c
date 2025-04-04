/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:34:47 by thodavid          #+#    #+#             */
/*   Updated: 2025/04/04 10:37:46 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_error(char *str)
{
    ft_putendl_fd(str, 1);
    exit(0);
}

long ft_ascii_to_pid(char *str)
{
    int i;
    int check;
    long r;
    //!!!!!!!!!!!!!!!!! attention verification si chaine vide si caratere alphabetique!!!!!!!!!!!!!!
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

// !!!! free si besoin le return de print bit
char *char_to_bit(char c)
{
    int i;
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

void check_arg(char *pid, char *msg)
{
    check_pid(pid);
    if (ft_strlen(msg) == 0)
        ft_error("MSG err");
}

int check_pid(char *msg)
{
    int i;

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
void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;
    while (*s)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
