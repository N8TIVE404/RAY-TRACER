# include <sphere.h>
# include <math.h>

Sphere construct_sphere(Point center, float radius){
    Sphere sphere;
    sphere.radius = radius;
    sphere.center = center;
    return sphere;
}

Object sphere_object(Sphere *s){
    Object sphere;
    sphere.object = s;
    sphere.hit = sphere_hit;

    return sphere;
}

bool sphere_hit(const void *object, Ray ray, float tMax, float tMin, HitRecord *record){
    Sphere *sphere = (Sphere *)object;
    Vector originTocenter = sub_vectors(sphere -> center, ray.origin);
    float a = dot_product(ray.direction, ray.direction);
    float b = dot_product(originTocenter, ray.direction) * -2.0;
    float c = dot_product(originTocenter, originTocenter) - sphere -> radius * sphere -> radius;

    float discriminant = b * b - (4 * a * c);
    if(discriminant < 0.0){
        record -> distance = -1.0;
        return false;
    }

    record -> distance = (-b - sqrt(discriminant)) / (2.0 * a);
    record -> center = sphere -> center;
    record -> point = at(ray, record -> distance);
    Vector n = scalar_divide(sub_vectors(record -> point, sphere -> center), sphere -> radius);

    record -> frontFace = dot_product(n, ray.direction) < 0.0;
    record -> normal = record -> frontFace ? n : scalar_multiply(n, -1.0);
    
    return true;
}
