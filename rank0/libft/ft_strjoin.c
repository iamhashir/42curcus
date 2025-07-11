/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:45:11 by mhashir           #+#    #+#             */
/*   Updated: 2023/09/04 03:34:08 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*nstr;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(sizeof(char) * len + 1);
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1, len + 1);
	ft_strlcat(nstr, s2, len + 1);
	return (nstr);
}
