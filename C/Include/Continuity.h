//
// Continuity.h
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C/Include/Continuity.h
//

#ifndef _CONTINUITY_H_
#define _CONTINUITY_H_

#include "./types.h"
#include <malloc.h>

void* (*Continuity_malloc)(const size_t) = malloc;

typedef struct Continuity_t {
    void*  data;
    size_t size;
} Continuity_t;

size_t
Continuity_init(
    const size_t quantity,
    ...
);

Continuity_t*
Continuity_resize(
    Continuity_t *const conty,
    const size_t        size,
    const bool          copy
);

Continuity_t*
Continuity_nResize(
    Continuity_t *const conty,
    const size_t        size,
    const size_t        desBeginIndex,
    const size_t        srcBeginIndex,
    const size_t        copySize
);

size_t
Continuity_free(
    const size_t quantity,
    ...
);

Continuity_t*
Continuity_nCopy(
    Continuity_t *const conty,
    const void *const   data,
    const size_t        size,
    const size_t        index
);

Continuity_t*
Continuity_copy(
    Continuity_t *const       desConty,
    const Continuity_t *const srcConty
);

#include "src/Continuity.c"

#endif /* _CONTINUITY_H_ */

