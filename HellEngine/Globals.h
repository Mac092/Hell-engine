#ifndef __H_GLOBALS__
#define __H_GLOBALS__

#include "SDL/include/SDL_rect.h"
#include "MemLeaks.h"

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )
#define MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )

/* Useful typedefs */
typedef unsigned int uint;

/* Deletes a buffer */
#define RELEASE( x ) \
    {									  \
       if( x != nullptr )   \
       {						      \
         delete x;                  \
	     x = nullptr;             \
       }                      \
    }

/* Deletes an array of buffers */
#define RELEASE_ARRAY( x ) \
	{                              \
       if( x != nullptr )              \
       {                            \
           delete[] x;                \
	       x = nullptr;                    \
		 }                            \
                              \
	 }

/* Configuration */
#define SCREEN_SIZE 3
#define SCREEN_WIDTH 384
#define SCREEN_HEIGHT 240
#define FULLSCREEN false
#define VSYNC true
#define TITLE "Hell's Engine"

#endif /* __H_GLOBALS__ */