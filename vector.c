#include <math.h>
#include "vector.h"

Vector vector(double x, double y, double z) {
    Vector vec = {x, y, z};
    return vec;
}

Vector v_add(Vector v1, Vector v2) {
    return vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector v_sub(Vector v1, Vector v2) {
    return vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector v_mul(Vector v, int n) {
    return vector(v.x * n, v.y * n, v.z * n);
}

double v_length(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector v_norm(Vector v) {
    double len = v_length(v);
    return vector(v.x / len, v.y / len, v.z / len);
}

Vector v_rotX(Vector v, double a) {
    double c = cos(a), s = sin(a);
    return vector(v.x, v.y * c - v.z * s, v.y * s + v.z * c);
}

Vector v_rotY(Vector v, double a) {
    double c = cos(a), s = sin(a);
    return vector(v.x * c + v.z * s, v.y, -v.x * s + v.z * c);
}

Vector v_rotZ(Vector v, double a) {
    double c = cos(a), s = sin(a);
    return vector(v.x * c + v.z * s, v.y, -v.x * s + v.z * c);
}

Vector v_rot(Vector v, double ax, double ay, double az) {
    Vector vec = vector(v.x, v.y, v.z);
    return vec;
}
