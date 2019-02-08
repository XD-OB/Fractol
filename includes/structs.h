#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct		s_complex
{
	long double		re;
	long double		im;
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
        double          y;
        int             isclick;
}                       t_mouse;

typedef struct		s_graphic
{
	void*		mlx;
	void*		win;
	unsigned int		max_iter;
	int		design;
	int		intern;
	long double		zoom;
	t_image		image;
	t_complex	j_cte;
	int		j_puis;
	int		m_puis;
}			t_graphic;

typedef struct	s_fractol
{
	t_graphic	*ptr;
	t_mouse		mouse;
	int		type;
	int		p;
	int		q;
}		t_fractol;

typedef struct	s_point
{
	float	x;
	float	y;
}		t_point;

#endif
