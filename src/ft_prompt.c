/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 01:41:33 by lucas             #+#    #+#             */
/*   Updated: 2016/03/21 14:04:55 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_logname(t_env *var)
{
	int		hoo;

	if ((hoo = ft_search_var(var, "LOGNAME")) < 0)
	{
		ft_putcolor("42", GREEN);
		return ;
	}
	while (hoo--)
		var = var->next;
	ft_putcolor(var->content, YELLOW);
	return ;
}

void	ft_pwdfolder(t_env *var)
{
	char	**files;
	int		hoo;

	if ((hoo = ft_search_var(var, "PWD")) < 0)
	{
		ft_logname(var);
		return ;
	}
	while (hoo--)
		var = var->next;
	hoo = 0;
	if (ft_strcmp(var->content, "/") == 0)
	{
		ft_putcolor("/", YELLOW);
		return ;
	}
	files = ft_strsplit(var->content, '/');
	while (files[hoo + 1])
		hoo++;
	ft_putcolor(files[hoo], YELLOW);
	return ;
}

void	ft_prompt(t_env *var)
{
	(void)var;
	ft_putcolor("[", YELLOW);
	ft_pwdfolder(var);
	ft_putcolor("]", YELLOW);
	ft_putstr("$> ");
}
