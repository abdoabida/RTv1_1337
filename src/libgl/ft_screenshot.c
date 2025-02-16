/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:23:47 by aabouibr          #+#    #+#             */
/*   Updated: 2019/10/05 14:34:52 by arezouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libgl.h"
#include "../../include/libft.h"

static void		ft_ppm_format(t_data *data, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(data->winwidth, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(data->winheight, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
}

static void		ft_save_screenshot(t_data *data, int *var)
{
	unsigned char	*buff;
	unsigned char	ppm;

	var[1] = -1;
	while (++var[1] < data->winheight)
	{
		var[2] = -1;
		while (++var[2] < data->winwidth)
		{
			var[3] = 3;
			buff = (unsigned char *)&data->image[var[2] +
				var[1] * data->winwidth];
			while (--var[3] >= 0)
			{
				ppm = buff[var[3]];
				ft_putnbr_fd(ppm, var[0]);
				ft_putchar_fd(' ', var[0]);
			}
		}
		ft_putchar_fd('\n', var[0]);
	}
	ft_putchar_fd('\n', var[0]);
}

void			*ft_screenshot(void *param)
{
	int				var[4];
	t_data			*data;

	data = (void *)param;
	var[0] = open("image.ppm", O_RDWR | O_CREAT, 0777);
	ft_ppm_format(data, var[0]);
	ft_save_screenshot(data, var);
	pthread_exit(NULL);
}
