/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 07:34:31 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/14 08:08:10 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
# define WIN_H

# define LENGHT_WIN		1600
# define HEIGHT_WIN		900

# define LIMIT_PANEL	(LENGHT_WIN / 6)

# define PANEL_POS_X	0
# define PANEL_POS_Y	0
# define PANEL_LENGHT	LIMIT_PANEL
# define PANEL_HEIGHT	HEIGHT_WIN

# define E_FRAME_POS_X	LIMIT_PANEL
# define E_FRAME_POS_Y	0
# define E_FRAME_LENGHT	(LENGHT_WIN - E_FRAME_POS_X)
# define E_FRAME_HEIGHT	HEIGHT_WIN

# define LENGHT_FRAME	(LENGHT_WIN / 20)
# define HEIGHT_FRAME	(LENGHT_WIN / 20)

# define I_FRAME_POS_X	(E_FRAME_POS_X + LENGHT_FRAME)
# define I_FRAME_POS_Y	(E_FRAME_POS_Y + HEIGHT_FRAME)
# define I_FRAME_LENGHT	(E_FRAME_LENGHT - 2 * LENGHT_FRAME)
# define I_FRAME_HEIGHT	(HEIGHT_WIN - 2 * HEIGHT_FRAME)

# define POS_X_MAP		(I_FRAME_POS_X + I_FRAME_LENGHT / 2)
# define POS_Y_MAP		(I_FRAME_POS_Y + I_FRAME_HEIGHT / 2)

# define HGT_SEP_PANEL	(PANEL_HEIGHT / 100)

# define ROT_POS_X		PANEL_POS_X
# define ROT_POS_Y		PANEL_POS_Y
# define ROT_LENGHT		PANEL_LENGHT
# define ROT_HEIGHT		(PANEL_HEIGHT / 8)
# define RO_LENGHT		(int)((double)ROT_LENGHT * 0.7)
# define RO_HEIGHT		(ROT_HEIGHT / 7)
# define RO_POS_X		(int)((double)ROT_LENGHT * 0.3)
# define RO_POS_Y		(ROT_HEIGHT / 2 + ROT_POS_Y)
# define R_BLOCK_LENGHT	(RO_LENGHT / 10)

# define HILLS_POS_X	PANEL_POS_X
# define HILLS_POS_Y	ROT_POS_Y + ROT_HEIGHT
# define HILLS_LENGHT	PANEL_LENGHT
# define HILLS_HEIGHT	(PANEL_HEIGHT / 8)
# define HILL_LENGHT	(int)((double)HILLS_LENGHT * 0.7)
# define HILL_HEIGHT	(HILLS_HEIGHT / 7)
# define HILL_POS_X		(int)((double)HILLS_LENGHT * 0.3)
# define HILL_POS_Y		(HILLS_HEIGHT / 2 + HILLS_POS_Y)
# define H_BLOCK_LENGHT	(HILL_LENGHT / 10)

# define STAT_POS_X		PANEL_POS_X
# define STAT_POS_Y		HILLS_POS_Y + HILLS_HEIGHT
# define STAT_LENGHT	PANEL_LENGHT
# define STAT_HEIGHT	(PANEL_HEIGHT / 16)
# define STAT_BTN_LGT	(int)((double)STAT_LENGHT * 0.1)
# define STAT_BTN_HGT	(int)((double)STAT_HEIGHT * 0.4)
# define STAT_BTN_Y		(STAT_POS_Y + STAT_HEIGHT / 2 - STAT_BTN_HGT / 2)
# define WIRE_POS_X		(STAT_LENGHT / 4 - STAT_BTN_LGT / 2)
# define POINT_POS_X	(STAT_LENGHT / 2 - STAT_BTN_LGT / 2)
# define FULL_POS_X		(STAT_LENGHT * 3 / 4 - STAT_BTN_LGT / 2)

# define COLORS_POS_X	PANEL_POS_X
# define COLORS_POS_Y	STAT_POS_Y + STAT_HEIGHT
# define COLORS_LENGHT	PANEL_LENGHT
# define COLORS_HEIGHT	(PANEL_HEIGHT / 2)
# define BLOCK_LENGHT	((double)COLORS_LENGHT * 0.4 + 1.0)
# define BLOCK_HEIGHT	(COLORS_HEIGHT / 15)
# define BLOCK_POS_X	((double)COLORS_LENGHT * 0.6)

# define SET_POS_X		PANEL_POS_X
# define SET_POS_Y		(COLORS_POS_Y + COLORS_HEIGHT)
# define SET_LENGHT		PANEL_LENGHT
# define SET_HEIGHT		(PANEL_HEIGHT - SET_POS_Y)
# define SET_IMG_WDH	(SET_HEIGHT / 6)
# define SET_IMG_POS_X	(SET_LENGHT / 10)
# define SET_WAY_POS_X	(SET_LENGHT / 4)
# define SET_WAY_LGT	(SET_LENGHT * 7 / 10)
# define SET_WAY_HGT	(SET_HEIGHT / 10)
# define DIFF_BTN_WAY	(SET_IMG_WDH / 2 - SET_WAY_HGT / 2)
# define SET_BTN_LGT	(SET_WAY_LGT / 10)

#endif
