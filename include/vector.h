# ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

struct HitRecord;

typedef struct Vector{
    float x, y, z;
} Vector;

Vector construct_vector(float x, float y, float z);

Vector add_vectors(Vector, Vector);
Vector sub_vectors(Vector, Vector);
Vector multiply(Vector, Vector);
Vector scalar_multiply(Vector, float);
Vector divide(Vector, Vector);
Vector scalar_divide(Vector, float);
Vector addf_vector(Vector, float);
Vector subf_vector(Vector, float);

void print_vector(Vector);

void add_assign(Vector*, const Vector*);
void sub_assign(Vector*, const Vector*);
void mul_assign(Vector*, const Vector*);
void mulf_assign(Vector*, float);
void div_assign(Vector*, const Vector*);
void divf_assign(Vector*, float);

float dot_product(Vector, Vector);
Vector cross_product(Vector, Vector);
void make_unit(Vector*);
Vector unit_vector(Vector a);

Vector random_vector();
Vector random_unit_vector();
Vector random_vector_on_hemisphere(struct HitRecord*);
float random_float();

float length(Vector);
float squared_length(Vector);

# endif
