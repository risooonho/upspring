/*
** DynASM encoding engine prototypes.
** Copyright (C) 2005-2006 Mike Pall. All rights reserved.
** Released under the MIT/X license. See dynasm.lua for full copyright notice.
*/

#ifndef _DASM_PROTO_H
#define _DASM_PROTO_H

#include <stddef.h>
#include <stdarg.h>

#define DASM_VERSION	10101	/* 1.1.1 */

#ifndef Dst_DECL
#define Dst_DECL	dasm_State *Dst
#endif

#ifndef Dst_GET
#define Dst_GET		(Dst)
#endif

#ifndef DASM_FDEF
#define DASM_FDEF	extern
#endif


/* Internal DynASM encoder state. */
typedef struct dasm_State dasm_State;

/* Action list type. */
typedef const unsigned char *dasm_ActList;


/* Initialize and free DynASM state. */
DASM_FDEF void dasm_init(Dst_DECL, int maxsection);
DASM_FDEF void dasm_free(Dst_DECL);

/* Setup global array. Must be called before dasm_setup(). */
DASM_FDEF void dasm_setupglobal(Dst_DECL, void **gl, unsigned int maxgl);

/* Grow PC label array. Can be called after dasm_setup(), too. */
DASM_FDEF void dasm_growpc(Dst_DECL, unsigned int maxpc);

/* Setup encoder. */
DASM_FDEF void dasm_setup(Dst_DECL, dasm_ActList actionlist);

/* Feed encoder with actions. Calls are generated by pre-processor. */
DASM_FDEF void dasm_put(Dst_DECL, int start, ...);

/* Link sections and return the resulting size. */
DASM_FDEF int dasm_link(Dst_DECL, size_t *szp);

/* Encode sections into buffer. */
DASM_FDEF int dasm_encode(Dst_DECL, void *buffer);

/* Get PC label offset. */
DASM_FDEF int dasm_getpclabel(Dst_DECL, unsigned int pc);

#ifdef DASM_CHECKS
/* Optional sanity checker to call between isolated encoding steps. */
DASM_FDEF int dasm_checkstep(Dst_DECL, int secmatch);
#else
#define dasm_checkstep(a, b)	0
#endif


#endif /* _DASM_PROTO_H */
