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
#define NO_HIS
#define HDF5
#undef DEFLATE
#define PERFECT_RESTART


/* general 2 */
#define CURVGRID
#define MASKING
#define NONLIN_EOS

#define SOLVE3D
#define SALINITY

#ifdef SOLVE3D
# define SPLINES_VDIFF
# define SPLINES_VVISC
# define RI_SPLINES
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
#undef LMD_MIXING
#ifdef LMD_MIXING
# define LMD_RIMIX
# define LMD_CONVEC
# define LMD_SKPP
# define LMD_NONLOCAL
# define LMD_SHAPIRO
# undef LMD_DDMIX
#endif

#define GLS_MIXING
#if defined GLS_MIXING || defined MY25_MIXING
# define KANTHA_CLAYSON
# define N2S2_HORAVG
# define RI_SPLINES
#endif

#ifdef PERFECT_RESTART
# undef  AVERAGES
# undef  DIAGNOSTICS_TS
# undef  DIAGNOSTICS_UV
# define OUT_DOUBLE
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
#  define ICE_ALB_EC92  /* for ice */
# endif
# undef SCORRECTION
#endif

/* tides */

#undef LTIDES
#ifdef LTIDES
# if defined AVERAGES && !defined USE_DEBUG
#  define FILTERED
# endif
# define SSH_TIDES
# define UV_TIDES
# define ADD_FSOBC
# define ADD_M2OBC
# define TIDES_ASTRO
# undef POT_TIDES

# define UV_DRAG_GRID
# define UV_QDRAG
# undef UV_LDRAG
# define ANA_DRAG
# define LIMIT_BSTRESS
#else
# define UV_DRAG_GRID
# define UV_QDRAG
# define ANA_DRAG
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
