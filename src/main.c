# include <vector.h>
# include <stdio.h>
# include <camera.h>
# include <ray.h>
# include <color.h>

int
main(void){
    Camera cam = initialize_camera(1.0, 1.333, 900, 2.0);

    printf("P3\n%d %d\n255\n", cam.width, cam.height);
    Sphere sphere = construct_sphere(construct_vector(0.0, 0.0, -1.0), 0.3);

    for(int i = 0; i < cam.height; i++){
        for(int j = 0; j < cam.width; j++){
            Ray ray = get_ray(&cam, i, j);
            Color color = color_ray(sphere, ray);

            printf("%d %d %d\n", (int)(255.99 * color.x), (int)(255.99 * color.y), (int)(255.99 * color.z));
        }
    }
    return 0;
}
