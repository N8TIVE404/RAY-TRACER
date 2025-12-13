# ifndef SPHERE_H
# define SPHERE_H

# include <hits.h>

typedef Vector Point;

typedef struct Sphere{
    float radius;
    Point center;
} Sphere;

Sphere construct_sphere(Point, float);
Object sphere_object(Sphere*);
bool sphere_hit(const void*, Ray, float, float, HitRecord*);

# endif
