# ifndef HITS_H
# define HITS_H

# include <vector.h>
# include <ray.h>

typedef struct HitRecord{
    float distance;
    bool frontFace;
    Vector point;
    Vector center;
} HitRecord;

typedef struct Object{
    void *object;
    bool (*hit)(const void*, Ray, float, float, HitRecord*);
} Object;

typedef struct World{
    Object *objects;
    int capacity, count;
} World;

World make_world(void);
void add_object(World*, Object);
bool object_hit(const World*, Ray, float, float, HitRecord*);

# endif
