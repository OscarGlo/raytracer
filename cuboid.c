#include "cuboid.h"

Cuboid cuboid(Vector pos, Vector size) {
    Cuboid c = {pos, size};
    return c;
}

Vector c_pos2(Cuboid c) {
    return v_add(c.pos, c.size);
}

int c_inside(Cuboid c, Vector v) {
    Vector pos2 = c_pos2(c);
    return v.x >= c.pos.x && v.x <= pos2.x &&
           v.y >= c.pos.y && v.y <= pos2.y &&
           v.z >= c.pos.z && v.z <= pos2.z;
}
