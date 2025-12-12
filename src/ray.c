# include <ray.h>

Vector at(Ray ray, float t){
    return add_vectors(ray.origin, scalar_multiply(ray.direction, t));
}

Ray get_ray(Camera *cam, int i, int j){
    Vector currentPixel = add_vectors(add_vectors(cam -> firstPixel, scalar_multiply(cam -> pixelDeltaV, i)),
                                      scalar_multiply(cam -> pixelDeltaU, j));

    Ray ray;
    ray.origin = cam -> center;
    ray.direction = sub_vectors(currentPixel, ray.origin);

    return ray;
}
