# ifndef COLOR_H
# define COLOR_H

# include <ray.h>
# include <vector.h>

struct World;
struct HitRecord;

typedef Vector Color;

Color color_ray(const struct World*, int, Ray, float, float, struct HitRecord*);
void print_pixel(Color);
float linear_to_gamma(float);

# endif
