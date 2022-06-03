//
// Continuity.c
//     Copyright (c) kuailedetongnian all rights reserved.
//

//
// /C/Include/src/Continuity.c
//

#ifndef _CONTINUITY_C_
#define _CONTINUITY_C_

#include "../Continuity.h"
#include "../types.h"
#include <stdarg.h>
#include <string.h>

size_t
Continuity_init(
    const size_t quantity,
    ...)
{
    va_list ap;
    va_start(ap, quantity);
    size_t success = 0;
    Continuity_t* conty = NULL;
    for(size_t i = 0; i < quantity; i++)
    {
        conty = va_arg(ap, Continuity_t*);
        if(conty != NULL) {
            conty->data = NULL;
            conty->size = 0;
            success++;
        }
    }
    va_end(ap);
    return success;
}

Continuity_t*
Continuity_resize(
    Continuity_t *const conty,
    const size_t        size,
    const bool          copy)
{
    if(conty == NULL) {
        return NULL;
    }
    if(size == 0) {
        Continuity_free(1, conty);
        return conty;
    }
    if(conty->data == NULL) {
        conty->data = Continuity_malloc(size);
        if(conty->data == NULL) {
            return NULL;
        }
        conty->size = size;
        return conty;
    }
    void *const oldContyData = conty->data;
    conty->data = Continuity_malloc(size);
    if(conty->data == NULL) {
        conty->data = oldContyData;
        return NULL;
    }
    conty->size = size;
    if(copy) {
        memcpy(conty->data, oldContyData, size);
    }
    return conty;
}

Continuity_t*
Continuity_nResize(
    Continuity_t *const conty,
    const size_t        size,
    const size_t        desBeginIndex,
    const size_t        srcBeginIndex,
    const size_t        copySize)
{
    if(conty == NULL) {
        return NULL;
    }
    if(size == 0) {
        Continuity_free(1, conty);
        return conty;
    }
    if(conty->size == 0) {
        return Continuity_resize(conty, size, 0);
    }
    if(desBeginIndex >= size || srcBeginIndex >= conty->size) {
        return Continuity_resize(conty, size, 1);
    }

    void *const oldContyData = conty->data;
    conty->data = Continuity_malloc(size);
    if(conty->data == NULL) {
        conty->data = oldContyData;
        return NULL;
    }
    memcpy((uint8_t*)conty->data + desBeginIndex, (uint8_t*)oldContyData + srcBeginIndex, copySize);
    conty->size = size;
    free(oldContyData);
    return conty;
}

size_t
Continuity_free(
    const size_t quantity,
    ...)
{
    va_list ap;
    va_start(ap, quantity);
    size_t success = 0;
    Continuity_t* conty = NULL;
    for(size_t i = 0; i < quantity; i++)
    {
        conty = va_arg(ap, Continuity_t*);
        if(conty != NULL) {
            free(conty);
            conty->data = NULL;
            conty->size = 0;
            success++;
        }
    }
    va_end(ap);
    return success;
}

Continuity_t*
Continuity_nCopy(
    Continuity_t *const conty,
    const void *const   data,
    const size_t        size,
    const size_t        index)
{
    if(conty == NULL) {
        return NULL;
    }
    if(data == NULL || index > conty->size) {
        return NULL;
    }
    if(size == 0) {
        return conty;
    }
    if(size + index > conty->size) {
        Continuity_resize(conty, size + index, 1);
    }
    if(conty->data == NULL) {
        conty->size = 0;
        return NULL;
    }
    memcpy((uint8_t*)conty->data + index, data, size);
    return conty;
}

Continuity_t*
Continuity_copy(
    Continuity_t *const       desConty,
    const Continuity_t *const srcConty)
{
    if(srcConty == NULL) {
        return NULL;
    }
    if(desConty == NULL) {
        Continuity_resize(desConty, srcConty->size, 0);
        if(desConty == NULL) {
            return NULL;
        }
        memcpy(desConty->data, srcConty->data, srcConty->size);
        return desConty;
    }
    if(desConty->size < srcConty->size) {
        Continuity_resize(desConty, srcConty->size, 0);
        if(desConty->data == NULL) {
            return NULL;
        }
        memcpy(desConty->data, srcConty->data, srcConty->size);
        return desConty;
    }
    memcpy(desConty->data, srcConty->data, srcConty->size);
    return desConty;
}

#endif /* _CONTINUITY_C_ */
