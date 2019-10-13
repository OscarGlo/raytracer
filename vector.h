#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    double x, y, z;
} Vector;

Vector vector(double x, double y, double z);

Vector v_add(Vector v1, Vector v2);
Vector v_sub(Vector v1, Vector v2);
Vector v_mul(Vector v, int n);

double v_length(Vector v);

Vector v_norm(Vector v);

Vector v_rotX(Vector v, double a);
Vector v_rotY(Vector v, double a);
Vector v_rotZ(Vector v, double a);
Vector v_rot(Vector v, double ax, double ay, double az);

#endif
