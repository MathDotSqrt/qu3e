//--------------------------------------------------------------------------------------------------
/**
@file	q3Render.h

@author	Randy Gaul
@date	10/10/2014

	Copyright (c) 2014 Randy Gaul http://www.randygaul.net

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:
	  1. The origin of this software must not be misrepresented; you must not
	     claim that you wrote the original software. If you use this software
	     in a product, an acknowledgment in the product documentation would be
	     appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not
	     be misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.
*/
//--------------------------------------------------------------------------------------------------

#ifndef Q3RENDER_H
#define Q3RENDER_H

#include "../common/q3Types.h"

//--------------------------------------------------------------------------------------------------
// q3Render
//--------------------------------------------------------------------------------------------------
class q3Render
{
public:
	virtual void SetPenColor( q3f32 r, q3f32 g, q3f32 b, q3f32 a = 1.0f ) = 0;
	virtual void SetPenPosition( q3f32 x, q3f32 y, q3f32 z ) = 0;
	virtual void SetScale( q3f32 sx, q3f32 sy, q3f32 sz ) = 0;

	// Render a line from pen position to this point.
	// Sets the pen position to the new point.
	virtual void Line( q3f32 x, q3f32 y, q3f32 z ) = 0;

	virtual void SetTriNormal( q3f32 x, q3f32 y, q3f32 z ) = 0;

	// Render a triangle with the normal set by SetTriNormal.
	virtual void Triangle(
		q3f32 x1, q3f32 y1, q3f32 z1,
		q3f32 x2, q3f32 y2, q3f32 z2,
		q3f32 x3, q3f32 y3, q3f32 z3
		) = 0;

	// Draw a point with the scale from SetScale
	virtual void Point( ) = 0;
};

#endif // Q3RENDER_H
