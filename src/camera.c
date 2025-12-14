# include <camera.h>
# include <hits.h>
# include <color.h>
# include <stdio.h>

Camera initialize_camera(float focalLength, float aspectRatio, int width, float viewPortWidth){
    Camera camera;
    camera.focalLength = focalLength;
    camera.aspectRatio = aspectRatio;
    camera.samplesPerPixel = 10;
    camera.depth = 50;
    camera.width = width;

    int height = width / aspectRatio;
    camera.height = height;
    camera.viewPortWidth = viewPortWidth;

    float viewPortHeight = viewPortWidth / aspectRatio;
    camera.viewPortHeight = viewPortHeight;
    camera.center = construct_vector(0.0, 0.0, 0.0);
    camera.horizontalVector = construct_vector(viewPortWidth, 0.0, 0.0);
    camera.verticalVector = construct_vector(0.0, -viewPortHeight, 0.0);
    camera.pixelDeltaV = scalar_divide(camera.verticalVector, camera.height);
    camera.pixelDeltaU = scalar_divide(camera.horizontalVector, camera.width);

    Vector viewCenter = construct_vector(0.0, 0.0, -focalLength);
    camera.upperLeft = sub_vectors(sub_vectors(viewCenter, scalar_multiply(camera.horizontalVector, 0.5)),
                                   scalar_multiply(camera.verticalVector, 0.5));
    camera.firstPixel = add_vectors(add_vectors(camera.upperLeft, scalar_multiply(camera.pixelDeltaV, 0.5)),
                                    scalar_multiply(camera.pixelDeltaU, 0.5));

    return camera;
}

void render(Camera *cam, const World *world){
    printf("P3\n%d %d\n255\n", cam -> width, cam -> height);
    float max = 10000000.0;
    float min = 1e-160;
    HitRecord record;

    for(int i = 0; i < cam -> height; i++){
        for(int j = 0; j < cam -> width; j++){
            Color color = {.x = 0.0, .y = 0.0, .z = 0.0};
            for(int samples = 0; samples < cam -> samplesPerPixel; samples++){
                Ray ray = get_ray(cam, i, j);
                Color c = color_ray(world, cam -> depth, ray, max, min, &record);
                add_assign(&color, &c);
            }

            print_pixel(scalar_divide(color, cam -> samplesPerPixel));
        }
    }
}
