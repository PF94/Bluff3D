/**
 @file X11Window.h
  
 A GWindow that uses the X11 API.

 @created 	  2005-06-04
 @edited  	  2005-06-04
    
 Copyright 2000-2005, Morgan McGuire.
 All rights reserved.
*/

#pragma once

#include <G3D/platform.h>

#ifndef G3D_LINUX
#error X11Window only supported on Linux
#endif

// Current implementation: X11Window *is* SDLWindow
#include "SDLWindow.h"

#define X11Window SDLWindow
