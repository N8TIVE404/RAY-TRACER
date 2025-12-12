# include <camera.h>

Camera initialize_camera(float focalLength, float aspectRatio, int width, float viewPortWidth){
    Camera camera;
    camera.focalLength = focalLength;
    camera.aspectRatio = aspectRatio;
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
