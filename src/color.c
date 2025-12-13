# include <color.h>
# include <stdio.h>

Color color_ray(const World *world, Ray ray, float tMax, float tMin, HitRecord *record){
    if(object_hit(world, ray, tMax, tMin, record) && record -> distance > 0.0){
        Vector N = random_unit_vector_in_hemisphere(record -> normal);
        Ray r;
        r.direction = N;
        r.origin = record ->point;
        return scalar_multiply(color_ray(world, r, tMax, tMin, record), 0.5);
    }

    Vector unitDirection = unit_vector(ray.direction);
    float a = (unitDirection.y + 1.0) * 0.5;

    return add_vectors(scalar_multiply(construct_vector(1.0, 1.0, 1.0), (1.0 - a)),
                       scalar_multiply(construct_vector(0.5, 0.7, 1.0), a));
}

void print_pixel(Color color){
    color = scalar_multiply(color, 255.99);
    printf("%d %d %d\n", (int)color.x, (int)color.y, (int)color.z);
}
