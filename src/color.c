# include <color.h>

Color color_ray(const World *world, Ray ray, float tMax, float tMin, HitRecord *record){
    if(object_hit(world, ray, tMax, tMin, record) && record -> distance > 0.0){
        Vector N = unit_vector(sub_vectors(at(ray, record -> distance), record -> center));
        N = addf_vector(N, 1.0);
        return scalar_multiply(N, 0.5);
    }

    Vector unitDirection = unit_vector(ray.direction);
    float a = (unitDirection.y + 1.0) * 0.5;

    return add_vectors(scalar_multiply(construct_vector(1.0, 1.0, 1.0), (1.0 - a)),
                       scalar_multiply(construct_vector(0.5, 0.7, 1.0), a));
}
