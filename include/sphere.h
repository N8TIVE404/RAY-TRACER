# ifndef SPHERE_H
# define SPHERE_H

# include <vector.h>
# include <ray.h>

struct Object;
struct HitRecord;

typedef Vector Point;

typedef struct Sphere{
    float radius;
    Point center;
} Sphere;

Sphere construct_sphere(Point, float);
struct Object sphere_object(Sphere*);
bool sphere_hit(const void*, Ray, float, float, struct HitRecord*);

# endif
