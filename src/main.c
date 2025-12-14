# include <vector.h>
# include <camera.h>
# include <ray.h>
# include <color.h>
# include <stdlib.h>
# include <sphere.h>
# include <hits.h>

int
main(void){
    Camera cam = initialize_camera(1.0, 1.333, 2160, 2.0);

    Sphere sphere = construct_sphere(construct_vector(0.0, -100.3, -1.0), 100.0);
    Sphere sphere1 = construct_sphere(construct_vector(0.0, 0.0, -1.0), 0.3);
    Object s0 = sphere_object(&sphere);
    Object s1 = sphere_object(&sphere1);
    World world = make_world();
    add_object(&world, s0);
    add_object(&world, s1);

    render(&cam, &world);

    free(world.objects);
    return 0;
}
