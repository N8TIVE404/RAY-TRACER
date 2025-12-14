# ifndef RAY_H
# define RAY_H

# include <vector.h>

struct Camera;

typedef struct Ray{
    Vector origin, direction;
} Ray;

Vector at(Ray, float);
Ray get_ray(struct Camera*, int, int);

# endif

