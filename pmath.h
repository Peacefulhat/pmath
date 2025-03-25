#ifndef PMATH_H
#define PMATH_H
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<math.h>

#define PMA_ASSERT assert
#define real_sqrt sqrtf

// real number type
typedef float real;

// vector type
typedef struct{
  real x,y;
}vec2;


// vector 2d 
real vec_mag2d(vec2 vec);
void vec_normalize2d(vec2 *vec);
void vec_sum2d(vec2*dst, vec2 a ,vec2 b);
void vec_scaled_add2d(vec2 *dst ,vec2 a, vec2 b, real scale);
void vec_sub2d(vec2*dst ,vec2 a, vec2 b);
real dot_product2d(vec2 a, vec2 b);
real dot_product_angled2d(vec2 a, vec2 b , real angle);
real cross_product2d(vec2 a, vec2 b);
real cross_product_angled2d(vec2 a, vec2 b , real angle);
real scalar_projection2d(vec2 a, vec2 b);
void vector_projection2d(vec2 *dst ,vec2 a, vec2 b);
void vec_reflect2d(vec2 *dst, vec2 v, vec2 n);
real vec_ang_btw(vec2 a, vec2 b);
void vec_rotate(vec2 *a,real angle);

// initilize a vector
#define VEC_INIT2D(vec, x, y) do { \
    PMA_ASSERT((vec) != NULL); \
    (vec)->x = (x); \
    (vec)->y = (y); \
} while(0)

// invert a vector
#define VEC_INVERT2D(vec) do {\
     PMA_ASSERT(vec!=NULL);\
     (vec)->x=-(vec)->x;\
     (vec)->y=-(vec)->y;\
  }while(0)

// scale multiplicaition
#define VEC_SCALAR_MUL2D(vec,value) do{\
  PMA_ASSERT(vec!=NULL);\
  (vec)->x*=value;\
  (vec)->y*=value;\
  }while(0)

#define VEC_PRINT2D(vec) printf("{x: %f, y: %f}\n", (vec)->x, (vec)->y)

#endif // PMATH_H


#ifdef PMATH_IMP

// calculate the magnitude
real vec_mag2d(vec2 vec){
    return real_sqrt(vec.x*vec.x+vec.y*vec.y);
}

// normalize the vector (vector into unit vector)
void vec_normalize2d(vec2 *vec){
  
  PMA_ASSERT(vec!=NULL);
  real mag=vec_mag2d(*vec);
  PMA_ASSERT(mag!=0);
  
  vec->x*=(real)1/mag;
  vec->y*=(real)1/mag;
}

// sum of two vectors
void vec_sum2d(vec2*dst, vec2 a ,vec2 b){
  
  PMA_ASSERT(dst!=NULL);
  dst->x=a.x+b.x;
  dst->y=a.y+b.y;
}

// difference of two vectors
void vec_sub2d(vec2*dst, vec2 a ,vec2 b){
  
  PMA_ASSERT(dst!=NULL);
  dst->x=a.x-b.x;
  dst->y=a.y-b.y;
}

// scaled vector addition
void vec_scaled_add2d(vec2 *dst,vec2 a, vec2 b, real scale){
  
  PMA_ASSERT(dst!=NULL);
  VEC_SCALAR_MUL2D(&b,scale);
  dst->x=a.x+b.x;
  dst->y=a.y+b.y;
}

// dot product of two vectors
real dot_product2d(vec2 a, vec2 b){
    return(a.x*b.x)+(a.y*b.y);
}

// dot product of two vectors with angle between them
real dot_product_angled2d(vec2 a, vec2 b , real angle){
  return vec_mag2d(a)*vec_mag2d(b)*cosf(angle);
}

// cross product of two vectors
real cross_product2d(vec2 a, vec2 b){
  return (a.x*b.y)-(a.y*b.x);
}

// cross product of two vectors with angle between them
real cross_product_angled2d(vec2 a, vec2 b , real angle){
  return vec_mag2d(a)*vec_mag2d(b)*sinf(angle);
}

// scaler projection of a on b
real scalar_projection2d(vec2 a, vec2 b){
  return dot_product2d(a,b)/vec_mag2d(b);  
}

// vector projection of a on b
void vector_projection2d(vec2 *dst ,vec2 a, vec2 b){
  PMA_ASSERT(dst!=NULL);
  real b_dot_b=dot_product2d(b,b);
  PMA_ASSERT(b_dot_b!=0);
  
  real scaling=dot_product2d(a,b)/b_dot_b;
  VEC_SCALAR_MUL2D(&b, scaling);
  dst=b;
}

// vector reflected across a normal 
void vec_reflect2d(vec2 *dst, vec2 v, vec2 n){
  PMA_ASSERT(dst!=NULL);
  real v_dot_n=dot_product2d(v,n);
  VEC_SCALAR_MUL2D(&n,2*v_dot_n);
  vec_sub(dst,v,n);
}

// angle between two vectors;
real vec_ang_btw(vec2 a, vec2 b){
  real a_dot_b=dot_product2d(a,b);
  real mag_a = vec_mag2d(a);
  real mag_b = vec_mag2d(b);
  return acosf(a_dot_b/(mag_a*mag_b));
}


// rotate vector by an angle
void vec_rotate(vec2 *a,real angle){
  
}

#endif//PMATH_IMP
