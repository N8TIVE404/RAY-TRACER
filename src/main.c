# include <vector.h>
# include <camera.h>
# include <ray.h>
# include <color.h>
# include <stdlib.h>

int
main(void){
    Camera cam = initialize_camera(1.0, 1.333, 900, 2.0);
    Sphere sphere = construct_sphere(construct_vector(0.0, -0.2, -1.0), 0.3);
    Sphere sphere1 = construct_sphere(construct_vector(0.0, -90, -1.0), 87);
    Object s0 = sphere_object(&sphere);
    Object s1 = sphere_object(&sphere1);
    World world = make_world();
    add_object(&world, s1);
    add_object(&world, s0);

    render(cam, &world);

    free(world.objects);
    return 0;
}
