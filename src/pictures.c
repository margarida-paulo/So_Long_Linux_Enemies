/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pictures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:27:37 by mvalerio          #+#    #+#             */
/*   Updated: 2023/10/17 20:56:19 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

image	*ft_make_picture_xpm(char *relative_path, params *par)
{
	image	*pic;
	int		img_width;
	int		img_height;

	pic = malloc(sizeof(image));
	if (!pic)
		return (0);
	pic->img = mlx_xpm_file_to_image(par->game, relative_path, &img_width, \
	&img_height);
	pic->addr = mlx_get_data_addr(pic->img, &(pic->pixel_bits), \
	&(pic->line_bytes), &(pic->endian));
	return (pic);
}

pictures	*ft_build_all_images(params *pms)
{
	pictures	*comps;

	comps = malloc(sizeof(pictures));
	if (!comps)
		return (0);
	comps->bckg = ft_make_picture_xpm("Images/bckg.xpm", pms);
	comps->walls = ft_make_picture_xpm("Images/walls.xpm", pms);
	comps->exit = ft_make_picture_xpm("Images/exit.xpm", pms);
	comps->mush = ft_make_picture_xpm("Images/mush.xpm", pms);
	comps->btfly_pu = ft_make_picture_xpm("Images/btfly_pu.xpm", pms);
	comps->btfly_pu2 = ft_make_picture_xpm("Images/btfly_pu2.xpm", pms);
	comps->btfly_pu3 = ft_make_picture_xpm("Images/btfly_pu3.xpm", pms);
	comps->btfly_pu4 = ft_make_picture_xpm("Images/btfly_pu4.xpm", pms);
	comps->btfly_pd = ft_make_picture_xpm("Images/btfly_pd.xpm", pms);
	comps->btfly_pd2 = ft_make_picture_xpm("Images/btfly_pd2.xpm", pms);
	comps->btfly_pd3 = ft_make_picture_xpm("Images/btfly_pd3.xpm", pms);
	comps->btfly_pd4 = ft_make_picture_xpm("Images/btfly_pd4.xpm", pms);
	comps->btfly_pl = ft_make_picture_xpm("Images/btfly_pl.xpm", pms);
	comps->btfly_pl2 = ft_make_picture_xpm("Images/btfly_pl2.xpm", pms);
	comps->btfly_pl3 = ft_make_picture_xpm("Images/btfly_pl3.xpm", pms);
	comps->btfly_pl4 = ft_make_picture_xpm("Images/btfly_pl4.xpm", pms);
	comps->btfly_pr = ft_make_picture_xpm("Images/btfly_pr.xpm", pms);
	comps->btfly_pr2 = ft_make_picture_xpm("Images/btfly_pr2.xpm", pms);
	comps->btfly_pr3 = ft_make_picture_xpm("Images/btfly_pr3.xpm", pms);
	comps->btfly_pr4 = ft_make_picture_xpm("Images/btfly_pr4.xpm", pms);
	comps->dying1 = ft_make_picture_xpm("Images/dying1.xpm", pms);
	comps->dying2 = ft_make_picture_xpm("Images/dying2.xpm", pms);
	comps->dying3 = ft_make_picture_xpm("Images/dying3.xpm", pms);
	comps->dying4 = ft_make_picture_xpm("Images/dying4.xpm", pms);
	comps->dying5 = ft_make_picture_xpm("Images/dying5.xpm", pms);
	comps->dying6 = ft_make_picture_xpm("Images/dying6.xpm", pms);
	comps->dying7 = ft_make_picture_xpm("Images/dying7.xpm", pms);
	comps->dying8 = ft_make_picture_xpm("Images/dying8.xpm", pms);
	comps->dying9 = ft_make_picture_xpm("Images/dying9.xpm", pms);
	comps->dying10 = ft_make_picture_xpm("Images/dying10.xpm", pms);
	comps->moves = ft_make_picture_xpm("Images/moves.xpm", pms);
	comps->enemy1 = ft_make_picture_xpm("Images/enemy1.xpm", pms);
	comps->enemy2 = ft_make_picture_xpm("Images/enemy2.xpm", pms);

	return (comps);
}
