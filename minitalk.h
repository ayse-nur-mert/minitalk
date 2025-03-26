/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amert <amert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:27:20 by amert             #+#    #+#             */
/*   Updated: 2025/03/25 14:51:35 by amert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# include "ft_printf.h"

# define ERR_ARGUMENT "there have to be at least 2 arguments"
# define ERR_PID "pid is not valid"
# define ERR_SIGACTION "failed to set signal handler"

#endif