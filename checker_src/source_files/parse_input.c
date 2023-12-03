/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:50:42 by dan               #+#    #+#             */
/*   Updated: 2023/12/03 13:39:31 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**========================================================================
 *                           parse_input
 ** file added to handle input as char *string.
 ** calculations on stack (as usual), new argv malloc'd, + argv reset
 *========================================================================**/
char	**parse_input(int *argc, char **argv)
{
	int		i;
	int		new_argc;
	char	tmp_argv[5000][11];
	char	**new_argv;

	initialize_tmp_argv(tmp_argv);
	new_argc = 0;
	i = 1;
	while (i < *argc)
	{
		if (is_string(argv[i]))
			parse_string(argv[i], tmp_argv, &new_argc);
		else
			ft_strlcpy(tmp_argv[new_argc++], argv[i], ft_strlen(argv[i]) + 1);
		i++;
	}
	*argc = new_argc + 1;
	new_argv = NULL;
	new_argv = build_new_argv(new_argc, tmp_argv);
	return (new_argv);
}

/**========================================================================
 *                           build_new_argv
 ** malloc used here ! beware memory management !
 *========================================================================**/
char	**build_new_argv(int new_argc, char tmp_argv[][11])
{
	int		i;
	char	**new_argv;

	new_argv = ft_calloc(new_argc + 2, sizeof(char *));
	if (!new_argv)
		return (NULL);
	new_argv[0] = ft_calloc(1, sizeof(char));
	if (!new_argv)
		return (free(new_argv), NULL);
	i = 1;
	while (i < new_argc + 1)
	{
		new_argv[i] = ft_calloc(ft_strlen(tmp_argv[i - 1]) + 1, sizeof(char));
		if (!new_argv)
		{
			while (i >= 0)
				free (new_argv[i--]);
			return (free(new_argv), NULL);
		}
		ft_strlcpy(new_argv[i], tmp_argv[i - 1],
			ft_strlen(tmp_argv[i - 1]) + 1);
		i++;
	}
	new_argv[i] = NULL;
	return (new_argv);
}

/**========================================================================
 *                           is_string
 *========================================================================**/
int	is_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			return (1);
		i++;
	}
	return (0);
}

/**========================================================================
 *                           parse_string
 ** malloc used here (ft_split) ! beware memory management !
 *========================================================================**/
void	parse_string(char *str, char tmp_argv[][11], int *new_argc)
{
	char	**tmp_input_tab;
	int		i;

	tmp_input_tab = NULL;
	tmp_input_tab = ft_split(str, ' ');
	i = 0;
	while (tmp_input_tab[i])
	{
		ft_strlcpy(tmp_argv[*new_argc], tmp_input_tab[i],
			ft_strlen(tmp_input_tab[i]) + 1);
		(*new_argc)++;
		i++;
	}
	i = 0;
	while (tmp_input_tab[i])
		free(tmp_input_tab[i++]);
	free(tmp_input_tab);
}

/**========================================================================
 *                          initialize_tmp_argv
 *========================================================================**/
void	initialize_tmp_argv(char tmp_argv[][11])
{
	int	i;
	int	j;

	i = 0;
	while (i < 5000)
	{
		j = 0;
		while (j < 11)
		{
			tmp_argv[i][j] = '\0';
			j++;
		}
		i++;
	}
}
