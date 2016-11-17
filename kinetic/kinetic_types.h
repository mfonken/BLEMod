/***********************************************************************************************//**
 * \file   kinetic_types.h
 * \brief  Types for kinetic math and filtering
 ***************************************************************************************************
 *      Author: Matthew Fonken
 **************************************************************************************************/

#ifndef KINETIC_KINETIC_TYPES_H_
#define KINETIC_KINETIC_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif
    
/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup kinetic
 * @{
 **************************************************************************************************/
    
/***************************************************************************************************
 Public Types
 ***************************************************************************************************/

/** Kinetic Type */
typedef struct _kinetic_t
{
    double     pos[3];          /**< Raw position */
    double     rot[3];          /**< Raw rotation */
    double     tru[3];          /**< Raw true loction */
    
    kalman_t   pos_f[3];        /**< Filtered position */
    kalman_t   rot_f[3];        /**< Filtered rotation */
    kalman_t   tru_f[3];        /**< Filtered true location */
} kinetic_t;
    
/** Kalman structure */
typedef struct _kalman_t
{
    double  K[2];               /**< Gain matrix */
    double  P_k[2][2];          /**< Error covariance matrix */
    double  rate;               /**< Rate */
    double  bias;               /**< Bias */
    double  value;              /**< Value */
    double  timestamp;          /**< Timestamp */
} kalman_t;



/** 2D Cartesian Cooridinate */
typedef struct _cartesian2_t
{
    double x;                   /**< X value */
    double y;                   /**< Y value */
} cartesian2_t;

/** Tait-Bryan Angles */
typedef struct _ang3_t
{
    double    a;                /**< Phi value */
    double    b;                /**< Theta value */
    double    c;                /**< Psi value */
} ang3_t;

/*! Simple 3d Vector */
typedef struct _vec3_t
{
    double    ihat;             /**< \$f\hat{i}\$f value */
    double    jhat;             /**< \$f\hat{j}\$f value */
    double    khat;             /**< \$f\hat{k}\$f value */
} vec3_t;

/** @} (end addtogroup kinetic) */
/** @} (end addtogroup Application) */

#endif /* KINETIC_KINETIC_TYPES_H_ */
