# ifndef RAY_H
# define RAY_H

# include <vector.h>
# include <camera.h>

typedef struct Ray{
    Vector origin, direction;
} Ray;

Vector at(Ray, float);
Ray get_ray(Camera*, int, int);

# endif

