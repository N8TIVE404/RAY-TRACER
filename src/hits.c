# include <hits.h>
# include <stdlib.h>
# include <stdio.h>

World make_world(void){
    World world;
    world.count = 0,
    world.objects = NULL;
    world.capacity = 0;
    return world;
}

void add_object(World *world, Object object){
    if(world -> count >= world -> capacity){
        ssize_t newCapacity = world -> capacity ? world -> capacity * 2 : 1;
        void *ptr = realloc(world -> objects, newCapacity * sizeof(Object));
        if(!ptr){
            fprintf(stderr, "Failed to allocate memory for scene!\n");
            exit(EXIT_FAILURE);
        }

        world -> objects = ptr;
        world -> capacity = newCapacity;
    }

    world -> objects[world -> count++] = object;
}

bool object_hit(const World *world, Ray ray, float tMax, float tMin, HitRecord *record){
    bool hitAnything = false;
    float closest = tMax;
    HitRecord temp;

    for(int i = 0; i < world -> count; i++){
        Object *currentObject = &(world -> objects[i]);
        if(currentObject -> hit(currentObject -> object, ray, closest, tMin, &temp)){
            hitAnything = true;
            closest = temp.distance;
            *record = temp;
        }
    }

    return hitAnything;
}
