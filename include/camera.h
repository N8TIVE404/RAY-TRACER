# ifndef CAMERA_H
# define CAMERA_H

# include <vector.h>

typedef struct Camera{
    float focalLength;
    int samplesPerPixel;
    float aspectRatio;
    int width, height;
    float viewPortWidth, viewPortHeight;
    Vector center;
    Vector verticalVector, horizontalVector;
    Vector upperLeft, firstPixel;
    Vector pixelDeltaU, pixelDeltaV;
} Camera;

Camera initialize_camera(float, float, int, float);
void render(Camera, const void*);

# endif
