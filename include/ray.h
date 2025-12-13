# ifndef RAY_H
# define RAY_H

# include <camera.h>

typedef struct Ray{
    Vector origin, direction;
} Ray;

Vector at(Ray, float);
Ray get_ray(Camera*, int, int);
Vector sample_pixel();

# endif

