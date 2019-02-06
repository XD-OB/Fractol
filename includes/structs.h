#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct		s_complex
{
	float		re;
	float		im;
}			t_complex;

typedef struct		s_image
{
	void		*void_ptr;
	char		*img;
	int		bpp;
	int		s_l;
	int		endian;
}			t_image;

typedef struct          s_mouse
{
        double             x;
        double             y;
        int             isclick;
}                       t_mouse;

typedef struct		s_graphic
{
	void*		mlx;
	void*		win;
	int		max_iter;
	int		map[16];
	int		design;
	int		intern;
	int		type;
	float		zoom;
	t_image		image;
	t_complex	j_cte;
	float		j_puis;
	float		m_puis;
}			t_graphic;

typedef struct	s_ready
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int		width;
	int		height;
	t_graphic	*ptr;
	t_mouse		mouse;
	int		p;
	int		q;
}		t_ready;

typedef struct	s_point
{
	float	x;
	float	y;
}		t_point;

#endif
