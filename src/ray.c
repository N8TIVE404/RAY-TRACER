# include <ray.h>
# include <camera.h>

Vector at(Ray ray, float t){
    return add_vectors(ray.origin, scalar_multiply(ray.direction, t));
}

Ray get_ray(Camera *cam, int i, int j){
    Vector vec = random_vector();
    Vector offset = construct_vector(vec.x - 0.5, vec.y - 0.5, 0.0);
    Vector currentPixel = add_vectors(add_vectors(cam -> firstPixel, scalar_multiply(cam -> pixelDeltaV, i + offset.y)),
                                      scalar_multiply(cam -> pixelDeltaU, j + offset.x));

    Ray ray;
    ray.origin = cam -> center;
    ray.direction = sub_vectors(currentPixel, ray.origin);

    return ray;
}
