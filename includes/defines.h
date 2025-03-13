/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:06:35 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 00:06:11 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define NUMPAD_1	65436
# define NUMPAD_2	65433
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_5	65437
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_8	65431
# define NUMPAD_9	65434
# define NUMKEY_1	49
# define NUMKEY_2	50
# define NUMKEY_3	51
# define NUMKEY_4	52
# define NUMKEY_5	53
# define NUMKEY_6	54
# define NUMKEY_7	55
# define NUMKEY_8	56
# define NUMKEY_9	57
# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_SPACE	32
# define KEY_Z		122
# define KEY_X		120
# define KEY_P		112
# define KEY_I		105
# define KEY_O		111
# define KEY_L		108
# define KEY_R		114
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_Q		113
# define KEY_W		119
# define KEY_E		101
# define KEY_ESC    65307

# define C_WHITE			0xffffff
# define C_GREY				0x303030
# define C_RED				0xff0000
# define C_GREEN			0x00ff00
# define C_LIGHT_GREEN		0x7fff00
# define C_VIOLET			0xbf3eff
# define C_SALAMON			0xe9967a
# define C_DRK_BLUE			0x050a30
# define C_BLACK			0x000000
# define C_BLUE				0x0000ff
# define C_YELLOW			0xffff00
# define C_CYAN				0x00ffff
# define C_PINK				0xff00ff
# define C_ORANGY			0xffa500
# define C_BLUEY			0x0492c2

# define WINDOW_NAME	 	"FDF Map visualizer"
# define MAX_PIXEL			1080000
# define SEGMNT_DEFAULT		C_WHITE
# define BACKGROUND_DEFAULT	C_GREY
# define C_TEXT				C_YELLOW
# define HEXADECIMAL_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

enum	e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum	e_bool
{
	FALSE,
	TRUE
};

#endif
