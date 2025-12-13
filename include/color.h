# ifndef COLOR_H
# define COLOR_H

# include <sphere.h>

typedef Vector Color;

Color color_ray(const World*, Ray, float, float, HitRecord*);
void print_pixel(Color color);

# endif
