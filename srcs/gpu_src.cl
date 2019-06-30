void		init_color(t_color *c, int i, double mult, int iter_max)
{
	c->mult = mult;
	c->i = i;
	c->nu = 0;
	c->nu_frac = 0;
	c->red = 0;
	c->green = 0;
	c->blue = 0;
	c->iter_max = iter_max;
}

unsigned int	aqua_blue(int iter_max, int i, double mult)
{
	t_color	s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLACK);
	s.red = sin(0.2 * (double)i);
	s.green = sin(0.2 * (double)i + 3) * 127 + 128;
	s.blue = sin(0.2 * (double)i + 3) * 127 + 128;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	smooth_aqua_blue(int iter_max, int i, double mult)
{
	t_color	s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (BLACK);
	s.nu = (i + 2 - log2(log2(s.mult))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(74 * s.nu_frac);
	s.green = (int)(205 * s.nu_frac);
	s.blue = (int)(196 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	shade_of_grey(int i, int iter_max, double mult)
{
	t_color	s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (WHITE);
	s.red = sin(0.3 * (double)i) * 127 + 128;
	s.green = sin(0.3 * (double)i) * 127 + 128;
	s.blue = sin(0.3 * (double)i) * 127 + 128;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	smooth_shade_of_grey(int i, int iter_max, double mult)
{
	t_color	s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (WHITE);
	s.nu = (i + 5 - log2(log2(sqrt(s.mult)))) / iter_max;
	s.nu_frac = s.nu - (int)s.nu;
	s.red = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	s.green = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	s.blue = (int)(255 * s.nu_frac + 255 * s.nu_frac);
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	rainbow(int iter_max, int i, double mult)
{
	t_color		s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (WHITE);
	s.red = sin(0.3 * (double)i + 0.0) * 127.0 + 128.0;
	s.green = sin(0.3 * (double)i + 2.0) * 127.0 + 128.0;
	s.blue = sin(0.3 * (double)i + 4.0) * 127.0 + 128.0;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int	picots(int iter_max, int i, double squares, double mult)
{
	double		index;
	t_color		s;

	init_color(&s, i, mult, iter_max);
	if (i == iter_max)
		return (WHITE);
	index = (double)i + 15.0 - (log2(log2(fabs(squares)))) / log2(2.0);
	s.red = sin(0.01 * (index + (4.0 * M_PI / 3.0))) * 230.0 + 25.0;
	s.green = sin(0.01 * (index + (2.0 * M_PI / 3.0))) * 74.0 + 181.0;
	s.blue = sin(0.01 * (index + (1.0 * M_PI / 3.0))) * 1.0 + 254.0;
	return ((UI)s.red << 16 | (UI)s.green << 8 | (UI)s.blue);
}

unsigned int		wow(double zi)
{
	if (zi > 0)
		return (BLACK);
	return (ORANGE);
}

unsigned int	choose_color(int palette, int i, int iter_max, double prod, double zr, double zi, double cr, double ci);

unsigned int	choose_color(int palette, int i, int iter_max, double prod, double zr, double zi, double cr, double ci)
{
	if (palette == 0)
		return (aqua_blue(iter_max, i, prod));
	else if (palette == 1)
		return (smooth_aqua_blue(iter_max, i, prod));
	else if (palette == 2)
		return (shade_of_grey(i, iter_max, prod));
	else if (palette == 3)
		return (smooth_shade_of_grey(i, iter_max, prod));
	else if (palette == 4)
		return (rainbow(iter_max, i, prod));
	else if (palette == 5)
		return (wow(zi));
}

double	ft_abs_double(double nb);

double	ft_abs_double(double nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

__kernel void choose_fractal(__global unsigned int *buffer,
									  int fractale,
									  int width,
									  int height,
									  double zoom,
									  double offx,
									  double offy,
									  int rond,
									  int palette,
									  double x1,
									  double x2,
									  double y1,
									  double y2,
									  double cr,
									  double ci,
									  double zr,
									  double zi,
									  int iter_max, 
									  int mx,
									  int my,
									  int midx,
									  int midy)
{
	unsigned int	pixel;
	int i;
	int x;
	int y;
	double prod;
	double tmp;

	pixel = get_global_id(0);
	y = pixel / width;
	x = pixel % width;
	prod = 0;
	i = 0;
	if (fractale == JULIA)
	{
		zr = (double)(x - midx) / zoom + x1 + offx;
		zi = (double)(y - midy) / zoom + y1 + offy;
	}
	else
	{
		cr = (double)(x - midx) / zoom + x1 + offx;
		ci = (double)(y - midy) / zoom + y1 + offy;
	}
	if (y >= height * 96 / 100)
		buffer[pixel] = 0x000000;
	else if (y >= height * 92 / 100)
		buffer[pixel] = 0xFFFFFF;
	else
	{
		while (prod < rond && i < iter_max)
		{
			if (fractale == SHIP)
			{
				tmp = zr * zr - zi * zi + cr;
				zi = 2 * ft_abs_double(zi * zr) + ci;
			}
			else if (fractale == BIRD)
			{
				tmp = (zr * zr - (zi * zi * 3)) * ft_abs_double(zr) + cr;
				zi = ((zr * zr * 3) - zi * zi) * ft_abs_double(zi) + ci;
			}
			else if (fractale == JULIA)
			{
				tmp = zr * zr - zi * zi + cr * width / 2 / mx;
				zi = 2 * zi * zr + ci * height / 2 / my;
			}
			else if (fractale == BUFFALO)
			{
				tmp = ft_abs_double(zr * zr - zi * zi) + cr;
				zi = 2 * ft_abs_double(zr * zi) + ci;
			}
			else
			{
				tmp = zr * zr - zi * zi + cr;
				zi = 2 * zi * zr + ci;
			}
			zr = tmp;
			i++;
			prod = zr * zr + zi * zi;
		}
		buffer[pixel] = choose_color(palette, i, iter_max, prod, zr, zi, cr, ci);
	}
}
