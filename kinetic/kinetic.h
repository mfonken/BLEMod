/*! \file spatial.h
    \brief Spatial Orientation Main\r\n
 
 NOTES:
 - IMU is for rotational data ONLY!
 - Positional data comes from camera triangulation module and beacons
 - Right-handed rotation
 
  Created by Matthew Fonken on 10/8/16.
 */


#ifndef kinetic_h
#define kinetic_h

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "kinetic_types.h"

#define 	absl(x) x > 0 ? x:-x

#define     HALF_PI             3.141596 / 2

#define     VISION_ZSTATE_IHAT  0
#define     VISION_ZSTATE_JHAT  0
#define     VISION_ZSTATE_KHAT -1

#define     D_AUG               0
#define     BEACON_DISTANCE     1

#define     VISION_WIDTH        640
#define     VISION_HEIGHT       480
#define     VISION_CENTER_X     VISION_WIDTH  / 2
#define     VISION_CENTER_Y     VISION_HEIGHT / 2

void initKinetics( void );
void initFilters( void );
vec3_t *dAugment( vec3_t *dvec, ang3_t *a);
void getAbsolutePosition( void );
void IMU_Update( void );

#endif /* kinetic_h */
