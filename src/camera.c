# include <camera.h>
# include <color.h>
# include <ray.h>
# include <hits.h>
# include <stdio.h>

Camera initialize_camera(float focalLength, float aspectRatio, int width, float viewPortWidth){
    Camera camera;
    camera.focalLength = focalLength;
    camera.aspectRatio = aspectRatio;
    camera.samplesPerPixel = 10;
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

void render(Camera cam, const void *w){
    printf("P3\n%d %d\n255\n", cam.width, cam.height);
    World *world = (World*)w;
    float max = 1000000.0;
    float min = 0.001;
    HitRecord record;

    for(int i = 0; i < cam.height; i++){
        for(int j = 0; j < cam.width; j++){
            Color color = {.x= 0, .y=0, .z=0};
            for(int sample = 0; sample < cam.samplesPerPixel; sample++){
                Ray ray = get_ray(&cam, i, j);
                Color c = color_ray(world, ray, max, min, &record);
                add_assign(&color, &c);
            }

            color = scalar_multiply(color, 1.0/cam.samplesPerPixel);
            print_pixel(color);
        }
    }
}
