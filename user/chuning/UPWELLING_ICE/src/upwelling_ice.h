/*
** svn $Id: upwelling.h 795 2016-05-11 01:42:43Z arango $
*******************************************************************************
** Copyright (c) 2002-2016 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Upwelling Test.
**
** Application flag:   UPWELLING_ICE
** Input script:       ocean_upwelling_ice.in
*/

/* general 1  */
#undef NO_HIS
#define HDF5
#define DEFLATE
#define PERFECT_RESTART

/* general 2 */
#define CURVGRID
#define MASKING
#define NONLIN_EOS

#define SALINITY
#define SOLVE3D
#define WET_DRY

#ifdef SOLVE3D
# define SPLINES_VDIFF
# define SPLINES_VVISC
# define RI_SPLINES
#endif

/* ice */
#ifdef SOLVE3D
# define  ICE_MODEL
# ifdef ICE_MODEL
#  define ANA_ICE
#  define  ICE_THERMO
#  define  ICE_MK
#  define  ICE_MOMENTUM
#  define  ICE_MOM_BULK
#  define  ICE_EVP
#  define  ICE_STRENGTH_QUAD
#  define  ICE_ADVECT
#  define  ICE_SMOLAR
#  define  ICE_UPWIND
#  define  ICE_BULK_FLUXES
#  define  ICE_I_O
# endif
#endif

/* output stuff */
#define NO_WRITE_GRID
#ifndef PERFECT_RESTART
# define RST_SINGLE
#endif
#define AVERAGES
#ifdef SOLVE3D
# undef DIAGNOSTICS_TS
# undef DIAGNOSTICS_UV
#endif

/* advection, dissipation, pressure grad, etc. */
#ifdef SOLVE3D
# define DJ_GRADPS
#endif

#define UV_ADV
#define UV_COR

#ifdef SOLVE3D
# define TS_U3HADVECTION
# define TS_C4VADVECTION
#endif

#define UV_VIS2
#define MIX_S_UV
#define VISC_GRID

#define TS_DIF2
#define MIX_S_TS

#ifdef SOLVE3D
# undef TS_DIF2
# undef MIX_GEO_TS
# undef DIFF_GRID
#endif

/* vertical mixing */
#ifdef SOLVE3D
# undef WTYPE_GRID  /* requires variable 'wtype_grid' in grid file */

# define LMD_MIXING
# ifdef LMD_MIXING
#  define LMD_RIMIX
#  define LMD_CONVEC
#  define LMD_SKPP
#  define LMD_NONLOCAL
#  define LMD_SHAPIRO
#  undef LMD_DDMIX
# endif

# undef GLS_MIXING
# undef MY25_MIXING
# if defined GLS_MIXING || defined MY25_MIXING
#  define KANTHA_CLAYSON
#  define N2S2_HORAVG
#  define RI_SPLINES
# endif
#endif

/* surface forcing */
#ifdef SOLVE3D
# define CORE_FORCING
# define BULK_FLUXES
# define CCSM_FLUXES
# if defined BULK_FLUXES || defined CCSM_FLUXES
#  define LONGWAVE_OUT
#  define SOLAR_SOURCE
#  define EMINUSP
#  define ALBEDO_CURVE  /* for water */
#  undef ICE_ALB_EC92  /* for ice */
# endif
# undef SCORRECTION
#else
# define ANA_SMFLUX
# define ANA_STFLUX
# define ANA_SSFLUX
#endif

/* tides */
#define LTIDES
#ifdef LTIDES
# if defined AVERAGES && !defined USE_DEBUG
#  undef FILTERED
# endif
# define SSH_TIDES
# define UV_TIDES
# define ADD_FSOBC
# define ADD_M2OBC
# undef TIDES_ASTRO
# undef POT_TIDES

# define UV_DRAG_GRID
# define UV_QDRAG
# undef UV_LDRAG
# define ANA_DRAG
# define LIMIT_BSTRESS
#else
# define UV_QDRAG
#endif

/* point sources (rivers, line sources) */
#ifdef SOLVE3D
# undef RUNOFF
# define ONE_TRACER_SOURCE
#endif

/* Boundary conditions...careful with grid orientation */
#define RADIATION_2D

/* ROMS quirks */
#ifdef SOLVE3D
# define ANA_BSFLUX
# define ANA_BTFLUX
#else
# define ANA_SMFLUX
#endif
