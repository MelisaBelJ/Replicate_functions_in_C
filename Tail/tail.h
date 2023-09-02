/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:48:31 by mbelmont          #+#    #+#             */
/*   Updated: 2023/08/24 08:55:21 by mbelmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <libgen.h>

int		ft_strlen(char *str);
void	ft_error(char *name, char *msg);
int		count_lines(char *name, int no_lines);
void	read_file(char *name, int m, int no_lines);
int		is_space(char c);
int		ft_atoi(char *str);
int		ft_str_is_numeric(char *str);
int		get_initial(char **args, int *is_c, int *num, int na);
void	ft_print(int na, char **args, int i, int init);

#endif