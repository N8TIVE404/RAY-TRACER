# ifndef COLOR_H
# define COLOR_H

# include <ray.h>
# include <sphere.h>
# include <vector.h>

typedef Vector Color;

Color color_ray(const World*, Ray, float, float, HitRecord*);

# endif
