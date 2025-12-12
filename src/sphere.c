# include <sphere.h>
# include <math.h>

Sphere construct_sphere(Point center, float radius){
    Sphere sphere;
    sphere.radius = radius;
    sphere.center = center;
    return sphere;
}

float sphere_hit(Sphere sphere, Ray ray){
    Vector originTocenter = sub_vectors(sphere.center, ray.origin);
    float a = dot_product(ray.direction, ray.direction);
    float b = dot_product(originTocenter, ray.direction) * -2.0;
    float c = dot_product(originTocenter, originTocenter) - sphere.radius * sphere.radius;

    float discriminant = b * b - (4 * a * c);
    if(discriminant < 0.0) return -1.0;

    return (-b - sqrt(discriminant)) / (2.0 * a);
}
