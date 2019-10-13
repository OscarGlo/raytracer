#include "vector.h"

#ifndef CUBOID_H
#define CUBOID_H

typedef struct Cuboid {
    Vector pos, size;
} Cuboid;

Cuboid cuboid(Vector pos, Vector size);

Vector c_pos2(Cuboid c);

int c_inside(Cuboid c, Vector v);

#endif
