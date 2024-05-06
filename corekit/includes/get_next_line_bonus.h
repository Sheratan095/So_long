/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "corekit.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//massimo numero di file che possono essere gestiti
# ifndef OPEN_MAX
#  define OPEN_MAX 2048
# endif

char	*get_next_line(int fd, t_bool last_call);

char	*ft_get_line(char *left_str);

char	*ft_strchr_gnl(char *s, int c);

char	*ft_strjoin_free_s1_gnl(char *s1, char *s2);

size_t	ft_strlen_gnl(char *s);

#endif
