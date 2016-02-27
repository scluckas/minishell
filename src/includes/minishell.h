/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lscariot@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:31:41 by lucas             #+#    #+#             */
/*   Updated: 2016/02/27 22:26:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define FT_LS_H

# include "libft.h"

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

int					ft_cmd(char *line, t_env *var);
t_env				*ft_env(char **env);
void				ft_show_env(t_env *var);

void				ft_free_list(t_env *var);
#endif
