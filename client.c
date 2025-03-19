/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amert <amert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:27:11 by amert             #+#    #+#             */
/*   Updated: 2025/03/19 13:38:50 by amert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_signal(int pid, int c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		bit--;
	}
}

int	main(int argc, char	**argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("exited with: %s\n", ERR_ARGUMENT);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("exited with: %s\n", ERR_PID);
		exit(1);
	}
	signal(SIGUSR1, handle_ack);
	str = argv[2];
	while (*str)
		send_signal(pid, *str++);
	send_signal(pid, '\0');
	return (0);
}
