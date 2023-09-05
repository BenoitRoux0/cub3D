/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroux <beroux@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 22:59:28 by beroux            #+#    #+#             */
/*   Updated: 2023/08/19 03:12:54 by beroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

typedef struct s_master_img t_master_img;

/** @struct s_color
 * @brief A struct to store color in four ints instead of one
 * @var uint32_t::a contain alpha component of color
 * @var uint32_t::r contain red component of color
 * @var uint32_t::g contain green component of color
 * @author beroux
 */
typedef struct s_color
{
	uint32_t	a;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
}	t_color;

/** @struct s_uint_img
 * @brief A struct to store an image in the form of a 2D uint32_t array
 * @var t_uint_img::content The 2D array who store the colors
 * @var t_uint_img::height The height of the image
 * @var t_uint_img::width The width of the image
 * @author beroux
 */
typedef struct s_uint_img
{
	uint32_t	**content;
	int			height;
	int			width;
}	t_uint_img;

/** @struct s_mlx_img
 * @brief a struct to store an image from the mlx
 * @var void *::content The array generated by the mlx to create an image
 * @var int::height The height of the image
 * @var int::width The width of the image
 * @author beroux
 */

typedef struct s_mlx_img
{
	void	*content;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_mlx_img;

/** @struct s_tileset
 * @brief a struct to store a tileset
 * @var t_uint_img::content The 2D array which contain images
 * @var int::height The height of the content array
 * @var int::width The width of the content array
 * @author beroux
 */
typedef struct s_tileset
{
	t_uint_img	***content;
	int 		height;
	int			 width;
}	t_tileset;

/** @fn t_uint_img  *init_img(int width, int height)
 * @brief create a new image empty with given dimensions
 *
 * @param width the width of new image
 * @param height the height of new image
 * @return t_img* the new image pointer
 *
 * @author beroux
 */
t_uint_img	*init_img(int width, int height);

/** @fn void    clear_img(t_uint_img*img)
 * @brief free all t_uint_imgcontent
 *
 * @param img the image to clear
 *
 * @author beroux
 */
void	clear_img(t_uint_img *img);

/** @fn void    clear_mlx_img(void *mlx_ptr, t_mlx_img *img)
 * @brief free all t_mlx_img content
 *
 * @param mlx_ptr the pointer returned by mlx_init()
 * @param img the image to clear
 *
 * @author beroux
 */
void	clear_mlx_img(void *mlx_ptr, t_mlx_img *img);

/** @fn void    img_to_mlx_img(void *mlx, t_mlx_img **dst, t_uint_img*src)
 * @brief copy a t_mlx_img in a t_img
 *
 * @param mlx the pointer returned by mlx_init()
 * @param dst the pointer to pointer to t_mlx_img to write
 * @param src pointer to t_uint_imgto copy
 *
 * @author beroux
 */
void	img_to_mlx_img(void *mlx, t_master_img **dst, t_uint_img*src);

/** @fn void    mlx_img_to_img(t_uint_img**dst, t_mlx_img *src)
 * @brief copy a t_mlx_img in a t_img
 *
 * @param dst the pointer to pointer to t_uint_imgto write
 * @param src pointer to pointer to t_uint_imgto copy
 *
 * @author beroux
 */
void	mlx_img_to_img(t_uint_img**dst, t_mlx_img *src);

/** @fn t_uint_img  *ft_xpm_to_img(void *mlx_ptr, char *path)
 * @brief  open an xpm file
 *
 * @param mlx_ptr the pointer returned by mlx_init()
 * @param path the path of the image to open
 * @return t_img* the new img
 *
 * @author beroux
 */
t_uint_img	*ft_xpm_to_img(void *mlx_ptr, char *path);

/** @fn t_uint_img  *ft_sub_img(t_uint_img*img, int pos[2], int width, int height)
 * @brief exctract a new image of given position and size from another image
 *
 * @param img the source image
 * @param pos the position where the new image is
 * @param width the width of the new imaghe
 * @param height the height of the new image
 * @return t_img* the new image mallocated
 *
 * @author beroux
 */
t_uint_img	*ft_sub_img(t_uint_img*img, int pos[2], int width, int height);

/** @fn t_tileset       *init_tileset(t_uint_img*img, int width, int height)
 * @brief create a new tileset
 *
 * @param img the image where the tileset is
 * @param width a tile width
 * @param height a tile height
 * @return t_tileset* the new tileset
 *
 * @author beroux
 */
t_tileset	*init_tileset(t_uint_img*img, int width, int height);

/** @fn void    clear_tileset(t_tileset *tileset)
 * @brief free all t_tileset content
 *
 * @param tileset the tileset to clear
 *
 * @author beroux
 */
void		clear_tileset(t_tileset *img);

/** @fn void    put_img_in_img(t_uint_img*dst, t_uint_img*src, int x, int y)
 * @brief a function to put a source image in a destination image
 * at a certain position
 *
 * @param dst the destination image for source image
 * @param src the source image to put in destination image
 * @param x the x pos of source image in destination image
 * @param y the y pos of source image in destination image
 *
 * @author beroux
 */
void		put_img_in_img(t_uint_img*dst, t_uint_img*src, int x, int y);

/** @fn void    rewrite_img(t_uint_img*img)
 * @brief set all pixels of t_uint_imgcontent to 0
 *
 * @param img the image to fill with 0
 *
 * @author beroux
 */
void		rewrite_img(t_uint_img*img);

/** @fn t_color uint32_t_to_color(uint32_t int_color)
 * @brief convert a uint32_t color to t_color color
 *
 * @param int_color the uint32_t color to convert
 * @return t_color the color conveted in t_color
 *
 * @author beroux
 */
t_color		uint32_t_to_color(uint32_t int_color);

/** @fn uint32_t        color_to_uint32_t(t_color color)
 * @brief convert a t_color color to uint32_t color
 *
 * @param color the t_color color to convert
 * @return uint32_t the color converted in uint32_t
 *
 * @author beroux
 */
uint32_t	color_to_uint32_t(t_color color);

/** @fn uint32_t        mix_colors(uint32_t bg, uint32_t fg)
 * @brief mix to colors in function of alphas
 *
 * @param bg background pixel
 * @param fg forground pixel
 * @return uint32_t the new color
 *
 * @author beroux
 */
uint32_t	mix_colors(uint32_t bg, uint32_t fg);

/** @fn t_uint_img  *img_dup(t_uint_img*src)
 * @brief malloc a copy of source image
 *
 * @param src image to duplicate
 * @return t_img* the new image
 *
 * @author beroux
 */
t_uint_img		*img_dup(t_uint_img *src);

/** @fn void    flip_horizontaly(t_uint_img*img)
 * @brief function to filp horizontaly an image
 * @warning this function alter the given image
 *
 * @param img the image to flip
 *
 * @author beroux
 */
void		flip_horizontaly(t_uint_img*img);

/** @fn void    flip_verticaly(t_uint_img*img)
 * @brief function to flip verticaly an image
 * @warning this function alter the given image
 *
 * @param img the image to flip
 *
 * @author beroux
 */
void		flip_verticaly(t_uint_img*img);

#endif