/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:27:39 by tbouma            #+#    #+#             */
/*   Updated: 2022/03/24 13:02:02 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	parent_free(t_pipex *pipex)
// {
// 	while (i >= 0)
// 	{
// 		free(str_arr[i]);
// 		i--;
// 	}
// 	free(str_arr);
// }

char	*find_command(char **dubbleptr, char *command)
{
	char	*temp;
	int		i;

	i = 0;
	while (dubbleptr[i])
	{
		temp = ft_strjoin(dubbleptr[i], "/");
		free(dubbleptr[i]);
		dubbleptr[i] = temp;
		temp = ft_strjoin(dubbleptr[i], command);
		free(dubbleptr[i]);
		dubbleptr[i] = temp;
		if (access(dubbleptr[i], F_OK) == 0)
		{
			return (dubbleptr[i]);
		}
		i++;
	}
	return (NULL);
}

char	**find_path(char **envp)
{
	char	*ptr;
	char	**dubbleptr;
	int		i;

	i = 0;
	while (!strstr(envp[i], "PATH="))
		i++;
	ptr = strstr(envp[i], "PATH=");
	ptr += 5;
	dubbleptr = ft_split(ptr, ':');
	return (dubbleptr);
}