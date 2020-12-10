//--------------------------------------------------------------------------------------------------
// q3Vec3.inl
//
//	Copyright (c) 2014 Randy Gaul http://www.randygaul.net
//
//	This software is provided 'as-is', without any express or implied
//	warranty. In no event will the authors be held liable for any damages
//	arising from the use of this software.
//
//	Permission is granted to anyone to use this software for any purpose,
//	including commercial applications, and to alter it and redistribute it
//	freely, subject to the following restrictions:
//	  1. The origin of this software must not be misrepresented; you must not
//	     claim that you wrote the original software. If you use this software
//	     in a product, an acknowledgment in the product documentation would be
//	     appreciated but is not required.
//	  2. Altered source versions must be plainly marked as such, and must not
//	     be misrepresented as being the original software.
//	  3. This notice may not be removed or altered from any source distribution.
//--------------------------------------------------------------------------------------------------

#include <cmath>

//--------------------------------------------------------------------------------------------------
// q3Vec3
//--------------------------------------------------------------------------------------------------
inline void q3Identity( q3Vec3& v )
{
	v.Set( q3r32( 0.0 ), q3r32( 0.0 ), q3r32( 0.0 ) );
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Mul( const q3Vec3& a, const q3Vec3& b )
{
	return q3Vec3( a.x * b.x, a.y * b.y, a.z * b.z );
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Dot( const q3Vec3& a, const q3Vec3& b )
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Cross( const q3Vec3& a, const q3Vec3& b )
{
	return q3Vec3(
		(a.y * b.z) - (b.y * a.z),
		(b.x * a.z) - (a.x * b.z),
		(a.x * b.y) - (b.x * a.y)
		);
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Length( const q3Vec3& v )
{
	return std::sqrt( v.x * v.x + v.y * v.y + v.z * v.z );
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3LengthSq( const q3Vec3& v )
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Normalize( const q3Vec3& v )
{
	q3r32 l = q3Length( v );

	if ( l != q3r32( 0.0 ) )
	{
		q3r32 inv = q3r32( 1.0 ) / l;
		return v * inv;
	}

	return v;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Distance( const q3Vec3& a, const q3Vec3& b )
{
	q3r32 xp = a.x - b.x;
	q3r32 yp = a.y - b.y;
	q3r32 zp = a.z - b.z;

	return std::sqrt( xp * xp + yp * yp + zp * zp );
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3DistanceSq( const q3Vec3& a, const q3Vec3& b )
{
	q3r32 xp = a.x - b.x;
	q3r32 yp = a.y - b.y;
	q3r32 zp = a.z - b.z;

	return xp * xp + yp * yp + zp * zp;
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Abs( const q3Vec3& v )
{
	return q3Vec3( q3Abs( v.x ), q3Abs( v.y ), q3Abs( v.z ) );
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Min( const q3Vec3& a, const q3Vec3& b )
{
	return q3Vec3( q3Min( a.x, b.x ), q3Min( a.y, b.y ), q3Min( a.z, b.z ) );
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Max( const q3Vec3& a, const q3Vec3& b )
{
	return q3Vec3( q3Max( a.x, b.x ), q3Max( a.y, b.y ), q3Max( a.z, b.z ) );
}

//--------------------------------------------------------------------------------------------------
inline const q3r32 q3MinPerElem( const q3Vec3& a )
{
	return q3Min( a.x, q3Min( a.y, a.z ) );
}

//--------------------------------------------------------------------------------------------------
inline const q3r32 q3MaxPerElem( const q3Vec3& a )
{
	return q3Max( a.x, q3Max( a.y, a.z ) );
}
