# ifndef CAMERA_H
# define CAMERA_H

# include <vector.h>

struct World;

typedef struct Camera{
    float focalLength;
    float aspectRatio;
    int samplesPerPixel, depth;
    int width, height;
    float viewPortWidth, viewPortHeight;
    Vector center;
    Vector verticalVector, horizontalVector;
    Vector upperLeft, firstPixel;
    Vector pixelDeltaU, pixelDeltaV;
} Camera;

Camera initialize_camera(float, float, int, float);
void render(Camera*, const struct World*);

# endif
