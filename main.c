/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <akosaca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:00:41 by akosaca              #+#    #+#             */
/*   Updated: 2025/03/05 09:00:42 by akosaca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int     file_name_control(char *file_name)
{
    size_t file_name_len;

    file_name_len =ft_strlen(file_name);

    if (file_name[file_name_len - 4] == '.' && \
        file_name[file_name_len - 3] == 'b' && \
        file_name[file_name_len - 2] == 'e' && \
        file_name[file_name_len - 1] == 'r')
    {
        return (0);
    }
    return (1);
}


int main(int ac, char *av[])
{
    t_map map;
    if (ac != 2)
    {
        return (1);
    }
    if (file_name_control(av[1]))
    {
        ft_printf("Ups! Dosya Uzantısı Hatalı!");
        return (1);
    }
    if (map_read_c(&map, av[1]))
    {
        ft_printf("Ups! Dosya okuma hatası");
        return (1);
    }


    return (0);
}