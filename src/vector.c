# include <vector.h>
# include <hits.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

Vector construct_vector(float x, float y, float z){
    Vector vec;
    vec.x = x; vec.y = y; vec.z = z;
    return vec;
}

Vector add_vectors(Vector a, Vector b){
    return construct_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector addf_vector(Vector a, float f){
    return construct_vector(a.x + f, a.y + f, a.z + f);
}

Vector sub_vectors(Vector a, Vector b){
    return construct_vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector subf_vector(Vector a, float f){
    return construct_vector(a.x - f, a.y - f, a.z -f);
}

Vector multiply(Vector a, Vector b){
    return construct_vector(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector scalar_multiply(Vector a, float f){
    return construct_vector(a.x * f, a.y * f, a.z * f);
}

Vector divide(Vector a, Vector b){
    return construct_vector(a.x / b.x, a.y / b.y, a.z / b.z);
};

Vector scalar_divide(Vector a, float f){
    if(f != 0.0) return construct_vector(a.x / f, a.y / f, a.z / f);
    return construct_vector(0.0, 0.0, 0.0);
}


void print_vector(Vector vector){
    printf("x: %.2f   y : %.2f   z: %.2f\n", vector.x, vector.y, vector.z);
}

void add_assign(Vector *a, const Vector *b){
    a -> x += b -> x; a -> y += b -> y; a -> z += b -> z;
}

void sub_assign(Vector *a, const Vector *b){
    a -> x -= b -> x; a -> y -= b -> y; a -> z -= b -> z;
}

void mul_assign(Vector *a, const Vector *b){
    a -> x *= b -> x; a -> y *= b -> y; a -> z *= b -> z;
}

void mulf_assign(Vector *a, float f){
    a -> x *= f; a -> y *= f; a -> z *= f;
}

void div_assign(Vector *a, const Vector *b){
    if(b -> x == 0 || b -> y == 0 || b -> z == 0){
       a -> x = 0; a -> y = 0; a -> z = 0;
    }else{
        a -> x /= b -> x;
        a -> y /= b -> y;
        a -> z /= b -> z;
    }
}

void divf_assign(Vector *a, float f){
    if(f != 0){
        a -> x /= f; a -> y /= f; a -> z /= f;
    } else{
        a -> x = 0; a -> y = 0; a -> z = 0;
    }
}

float dot_product(Vector a, Vector b){
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

float length(Vector a){
    return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

float squared_length(Vector a){
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

void make_unit(Vector *a){
    float k =  1.0 / length((*a));
    mulf_assign(a, k);
}

Vector cross_product(Vector a, Vector b){
    return construct_vector((a.y * b.z - a.z * b.y),
                (- a.x * b.z + a.z * b.x),
                (a.x * b.y - a.y * b.x));
}

Vector unit_vector(Vector a){
    return scalar_divide(a, length(a));
}


float random_float(){
    return (drand48() * 2) - 1.0;
}

Vector random_vector(){
    srand(time(NULL));
    return construct_vector(random_float(), random_float(), random_float());
}

Vector random_unit_vector(){
    while(true){
        Vector p = random_vector();
        float squaredLength = squared_length(p);
        if(1e-160 < squaredLength && squaredLength <= 1.0){
            return scalar_divide(p, sqrt(squaredLength));
        }
    }
}

Vector random_vector_on_hemisphere(HitRecord *record){
    Vector vec = random_unit_vector();
    if(dot_product(record -> normal, vec) > 0.0) return vec;
    return scalar_multiply(vec, -1.0);
}
