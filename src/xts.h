/*
Header file for using internal C-level facilities
provided by xts.

This is not 100% designed for end users, so
any user comments and bug reports are very
welcomed.

Copyright Jeffrey A. Ryan 2008

This source is distributed with the same license
as the full xts software, GPL3.
*/
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

#ifndef _XTS
#define _XTS


/*
INTERNAL SYMBOLS
*/
#define  xts_IndexSymbol                install("index")
#define  xts_ClassSymbol                install(".CLASS")
#define  xts_IndexFormatSymbol          install(".indexFORMAT")
#define  xts_IndexClassSymbol           install(".indexCLASS")


/*
DATA TOOLS
*/
#define  xts_ATTRIB(x)                  coerceVector(do_xtsAttributes(x),LISTSXP)
#define  xts_COREATTRIB(x)              coerceVector(do_xtsCoreAttributes(x),LISTSXP)

// attr(x, 'index') or .index(x)
#define  GET_xtsIndex(x)                getAttrib(x, xts_IndexSymbol)
#define  SET_xtsIndex(x,value)          setAttrib(x, xts_IndexSymbol, value)

// attr(x, '.indexCLASS') or indexClass(x)
#define  GET_xtsIndexClass(x)           getAttrib(x, xts_IndexClassSymbol)
#define  SET_xtsIndexClass(x,value)     setAttrib(x, xts_IndexvalueSymbol, value)

// attr(x, '.indexFORMAT') or indexFormat(x)
#define  GET_xtsIndexFormat(x)          getAttrib(x, xts_IndexFormatSymbol)
#define  SET_xtsIndexFormat(x,value)    setAttrib(x, xts_IndexFormatSymbol, value)

// attr(x, '.CLASS') or CLASS(x)
#define  GET_xtsCLASS(x)                getAttrib(x, xts_ClassSymbol)
#define  SET_xtsCLASS(x,value)          setAttrib(x, xts_ClassSymbol, value)

/*
FUNCTIONS
*/
SEXP do_xtsAttributes(SEXP x);              // xtsAttributes i.e. user-added attributes
SEXP do_xtsCoreAttributes(SEXP x);          /* xtsCoreAttributes xts-specific attributes
                                               CLASS, .indexFORMAT, .indexCLASS & class */

SEXP add_xts_class(SEXP x);
SEXP lagXts(SEXP x, SEXP k, SEXP pad);
SEXP do_is_ordered(SEXP x, SEXP increasing, SEXP strictly);
SEXP mergeXts(SEXP args);
SEXP do_rbind_xts(SEXP x, SEXP y, SEXP env);
SEXP rbindXts(SEXP args);
SEXP do_subset_xts(SEXP x, SEXP sr, SEXP sc);
SEXP number_of_cols(SEXP args);
SEXP col_names(SEXP args);

SEXP tryXts(SEXP x);


void copy_xtsAttributes(SEXP x, SEXP y);    // internal only
void copy_xtsCoreAttributes(SEXP x, SEXP y);// internal only    

int isXts(SEXP x);                          // is.xts analogue
#endif /* _XTS */
