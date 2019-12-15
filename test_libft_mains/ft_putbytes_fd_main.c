/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charmstr <charmstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:23:53 by charmstr          #+#    #+#             */
/*   Updated: 2019/12/15 16:23:58 by charmstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc __attribute__((unused)), char *argv[])
{
	int tab[4] = {251708297, 2, 3, 4};
	ft_putbytes_fd(tab, sizeof(tab), sizeof(*tab), 1);
	return (0);
}
