# ifndef SPHERE_H
# define SPHERE_H

# include <vector.h>
# include <stdbool.h>
# include <ray.h>

typedef Vector Point;

typedef struct Sphere{
    float radius;
    Point center;
} Sphere;

Sphere construct_sphere(Point, float);
float sphere_hit(Sphere, Ray);

# endif
