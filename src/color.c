# include <color.h>
# include <hits.h>
# include <stdio.h>
# include <math.h>

Color color_ray(const World *world, int depth, Ray ray, float tMax, float tMin, HitRecord *record){
    if(depth <= 0) return construct_vector(0.0, 0.0, 0.0);
    if(object_hit(world, ray, tMax, tMin, record) && record -> distance > 0.0){
        Vector N = add_vectors(record -> normal, random_unit_vector());
        Ray r = {.direction = N, .origin = record -> point};

        return scalar_multiply(color_ray(world, depth - 1, r, tMax, tMin, record), 0.5);
    }

    Vector unitDirection = unit_vector(ray.direction);
    float a = (unitDirection.y + 1.0) * 0.5;

    return add_vectors(scalar_multiply(construct_vector(1.0, 1.0, 1.0), (1.0 - a)),
                       scalar_multiply(construct_vector(0.5, 0.7, 1.0), a));
}

float linear_to_gamma(float linearValue){
    if(linearValue > 0.0) return sqrt(linearValue);
    return 0.0;
}
void print_pixel(Color pixelColor){
    pixelColor.x = linear_to_gamma(pixelColor.x);
    pixelColor.y = linear_to_gamma(pixelColor.y);
    pixelColor.z = linear_to_gamma(pixelColor.z);
    Color color = scalar_multiply(pixelColor, 255.99);
    printf("%d %d %d\n", (int)color.x, (int)color.y, (int)color.z);
}
