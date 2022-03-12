/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:00:50 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/04 13:20:04 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strdup2(char *src, int add_enter);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strjoin2(char const *s1, char const *s2, int add_enter);

#endif //GET_NEXT_LINE_H
