# include <vector.h>
# include <stdio.h>
# include <camera.h>
# include <ray.h>
# include <color.h>
# include <stdlib.h>

int
main(void){
    Camera cam = initialize_camera(1.0, 1.333, 900, 2.0);

    printf("P3\n%d %d\n255\n", cam.width, cam.height);
    Sphere sphere = construct_sphere(construct_vector(0.4, 0.0, -1.0), 0.3);
    Sphere sphere1 = construct_sphere(construct_vector(-0.4, 0.0, -1.0), 0.3);
    Object s0 = sphere_object(&sphere);
    Object s1 = sphere_object(&sphere1);
    World world = make_world();
    add_object(&world, s0);
    add_object(&world, s1);
    float max = 10000000.0;
    float min = 0.001;
    HitRecord record;

    for(int i = 0; i < cam.height; i++){
        for(int j = 0; j < cam.width; j++){
            Ray ray = get_ray(&cam, i, j);
            Color color = color_ray(&world, ray, max, min, &record);

            printf("%d %d %d\n", (int)(255.99 * color.x), (int)(255.99 * color.y), (int)(255.99 * color.z));
        }
    }

    free(world.objects);
    return 0;
}
