# include <ray.h>

Vector at(Ray ray, float t){
    return add_vectors(ray.origin, scalar_multiply(ray.direction, t));
}

Ray get_ray(Camera *cam, int i, int j){
    Vector offset = sample_pixel();
    Vector currentPixel = add_vectors(add_vectors(cam -> firstPixel, scalar_multiply(cam -> pixelDeltaV, offset.y + i)),
                                      scalar_multiply(cam -> pixelDeltaU, offset.x + j));

    Ray ray;
    ray.origin = cam -> center;
    ray.direction = sub_vectors(currentPixel, ray.origin);

    return ray;
}

Vector sample_pixel(){
    Vector vec = random_vector();
    return construct_vector(vec.x - 0.5, vec.y - 0.5, 0.0);
}
