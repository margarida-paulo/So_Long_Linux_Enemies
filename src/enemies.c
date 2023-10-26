/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:20:48 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/26 11:52:30 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


void	ft_print_map(params *pms)
{
	size_t	y = 0;
	size_t	x = 0;

	while ((pms->map)[y])
	{
		x = 0;
		while ((pms->map)[y][x])
		{
			ft_printf("%c", (pms->map)[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n\n\n");
}

void	ft_add_enemy(params *pms, enemy *current_enemy, size_t x, size_t y)
{
	enemy	*current;

	current_enemy->x = x;
	current_enemy->y = y;
	pms->map[y][x] = 'B';
	current = pms->enemy_list->head;
	if (!(pms->enemy_list->head))
	{
		pms->enemy_list->head = current_enemy;
		pms->enemy_list->head->next = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = current_enemy;
		current->next->next = NULL;
	}
	mlx_put_image_to_window(pms->game, \
	pms->win, pms->all->enemyr1->img, x * S, y * S);
}

void	ft_loop_map(params *pms, size_t *x, size_t *y)
{
	if (pms->map[*y][(*x) + 1])
		(*x)++;
	else
	{
		(*y)++;
		(*x) = 0;
	}
}



void	ft_build_enemies(params *pms)
{
	enemy	*current_enemy;
	size_t	place;
	size_t	*xy;

	xy = malloc(sizeof(int) * 2);
	if (!xy)
		return ;
	xy[0] = 1;
	xy[1] = 1;
	current_enemy = malloc(sizeof(enemy));
	if (!current_enemy)
		return ;
	place = rand() % pms->bckg_n;
	while (place > 1)
	{
		if (pms->map[xy[1]][xy[0]] == '0')
			place--;
		ft_loop_map(pms, &(xy[0]), &(xy[1]));
	}
	while (pms->map[xy[1]][xy[0]] != '0')
		ft_loop_map(pms, &(xy[0]), &(xy[1]));
	ft_add_enemy(pms, current_enemy, xy[0], xy[1]);
	pms->bckg_n--;
}


void	ft_enemies(params *pms)
{
	size_t			i;

	i = 0;
	pms->enemies_n = (pms->bckg_n) / ENEMY_RATIO;
	if (!(pms->enemies_n))
		return ;
	pms->enemy_list = malloc(sizeof(enemy));
	if (!(pms->enemy_list))
		return ;
	pms->enemy_list->head = NULL;
	while (i < pms->enemies_n)
	{
		ft_build_enemies(pms);
		i++;
	}
}
