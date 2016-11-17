/*! \file matrix.h
\brief Matrix Math

Created by Matthew Fonken on 10/10/16.
*/

#ifndef matrix_h
#define matrix_h

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include "kinetic_types.h"

vec3_t * zxyTransform(  vec3_t *x, ang3_t *rot, bool reverse);
vec3_t * yxzTransform( vec3_t * x, ang3_t * rot, bool reverse);
void subtractvec3_ts( vec3_t * x, vec3_t * y );
double lengthOfvec3_t( vec3_t * vec );
void normalizevec3_t( vec3_t * vec );
double get2dDistance( cartesian2_t *a, cartesian2_t *b );

#endif /* matrix_h */
