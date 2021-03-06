/*
** svn $Id: upwelling.h 795 2016-05-11 01:42:43Z arango $
*******************************************************************************
** Copyright (c) 2002-2016 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Glacier Bay Test.
**
** Application flag:   GB
** Input script:       ocean_GB-SPINUP.in
*/

/* general 1 */

#define HDF5
#define DEFLATE
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
#define WET_DRY
#define STATIONS

/* ice */

#ifdef SOLVE3D
# define ICE_MODEL
# ifdef ICE_MODEL
#  define ANA_ICE
#  define ICE_THERMO
#  define ICE_MK
#  define ICE_MOMENTUM
#  define ICE_MOM_BULK
#  define ICE_EVP
#  define ICE_STRENGTH_QUAD
#  define ICE_ADVECT
#  define ICE_SMOLAR
#  define ICE_UPWIND
#  define ICE_BULK_FLUXES
#  define ICE_I_O
#  define ICE_ALB_EC92  /* for ice */
# endif
#endif

/* output stuff */

#define NO_WRITE_GRID
#undef NO_HIS
#define AVERAGES
#undef AVERAGES2

#ifdef SOLVE3D
# undef DIAGNOSTICS_TS
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

/* vertical mixing */

#ifdef SOLVE3D
# undef WTYPE_GRID

# undef LMD_MIXING
# ifdef LMD_MIXING
#  define LMD_RIMIX
#  define LMD_CONVEC
#  define LMD_SKPP
#  undef LMD_BKPP
#  define LMD_NONLOCAL
#  define LMD_SHAPIRO
#  undef LMD_DDMIX
# endif

# define GLS_MIXING
# undef MY25_MIXING

# if defined GLS_MIXING || defined MY25_MIXING
#  define KANTHA_CLAYSON
#  define N2S2_HORAVG
#  define CRAIG_BANNER
#  define CHARNOK
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
# endif
# undef SCORRECTION
#else
# define ANA_SMFLUX
# define ANA_STFLUX
# define ANA_SSFLUX
#endif

/* point sources (rivers, line sources) */

/* Not using Runoff now */
#ifdef SOLVE3D
# undef ANA_SSFLUX
# define ONE_TRACER_SOURCE
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
# define RAMP_TIDES
# undef TIDES_ASTRO
# undef POT_TIDES
#endif

#define UV_DRAG_GRID
#define ANA_DRAG
#undef UV_QDRAG
#define UV_LDRAG
#undef LIMIT_BSTRESS

/* Boundary conditions...careful with grid orientation */

#define RADIATION_2D

/* roms quirks */

#ifdef SOLVE3D
# define ANA_BSFLUX
# define ANA_BTFLUX
#else
# define ANA_SMFLUX
#endif
