/**
 @file debug.h

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2001-08-26
 @edited  2006-02-16

  Copyright 2000-2006, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3D_DEBUG_H
#define G3D_DEBUG_H

#include "platform.h"

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#include "debugPrintf.h"
#include "debugAssert.h"

namespace G3D {

#ifdef G3D_WIN32
    // Turn off 64-bit warnings
#   pragma warning(push)
#   pragma warning( disable : 4312)
#   pragma warning( disable : 4267)
#   pragma warning( disable : 4311)
#endif


/**
 Useful for debugging purposes.
 */
    inline bool isValidHeapPointer(const void *x) {
#ifdef _MSC_VER
        return 
            (x != (void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee);
#else
        return x != NULL;
#endif
    }

/**
 Returns true if the pointer is likely to be
 a valid pointer (instead of an arbitrary number). 
 Useful for debugging purposes.
 */
    inline bool isValidPointer(const void *x) {
#ifdef _MSC_VER
        return x != ((void*)0xcccccccc) && (x != (void*)0xdeadbeef) && (x != (void*)0xfeeefeee);
#else
        return x != NULL;
#endif
    }

#ifdef G3D_WIN32
#   pragma warning(pop)
#endif

}

#endif
