/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:35:04 by mhashir           #+#    #+#             */
/*   Updated: 2025/08/22 22:35:07 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len) {
    size_t i;
    size_t j;

    if (!*needle)
        return ((char *)haystack);
    for (i = 0; haystack[i] && i < len; i++) {
        for (j = 0; needle[j] && haystack[i + j] && i + j < len; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (!needle[j])
            return ((char *)&haystack[i]);
    }
    return (NULL);
}
