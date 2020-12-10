//--------------------------------------------------------------------------------------------------
/**
@file	q3Quaternion.h

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

#ifndef Q3QUATERNION_H
#define Q3QUATERNION_H

#include "../common/q3Types.h"
#include "q3Vec3.h"

//--------------------------------------------------------------------------------------------------
// q3Quaternion
//--------------------------------------------------------------------------------------------------
struct q3Mat3;

class q3Quaternion
{
public:
	union
	{
		q3r32 v[ 4 ];

		struct
		{
			q3r32 x;
			q3r32 y;
			q3r32 z;

			q3r32 w;
		};
	};

	q3Quaternion( );
	q3Quaternion( q3r32 a, q3r32 b, q3r32 c, q3r32 d );
	q3Quaternion( const q3Vec3& axis, q3r32 radians );

	void Set( const q3Vec3& axis, q3r32 radians );
	void ToAxisAngle( q3Vec3* axis, q3r32* angle ) const;
	void Integrate( const q3Vec3& dv, q3r32 dt );

	const q3Quaternion operator*( const q3Quaternion& rhs ) const;
	q3Quaternion& operator*=( const q3Quaternion& rhs );

	const q3Mat3 ToMat3( void ) const;
};

//--------------------------------------------------------------------------------------------------
inline const q3Quaternion q3Normalize( const q3Quaternion& q )
{
	q3r32 x = q.x;
	q3r32 y = q.y;
	q3r32 z = q.z;
	q3r32 w = q.w;

	q3r32 d = q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z;

	if( d == 0 )
		w = q3r32( 1.0 );

	d = q3r32( 1.0 ) / std::sqrt( d );

	if ( d > q3r32( 1.0e-8 ) )
	{
		x *= d;
		y *= d;
		z *= d;
		w *= d;
	}

	return q3Quaternion( x, y, z, w );
}

#endif // Q3QUATERNION_H
