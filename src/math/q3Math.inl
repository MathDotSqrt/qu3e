//--------------------------------------------------------------------------------------------------
// q3Math.inl
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

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Invert( q3r32 a )
{
	return a != 0.0f ? 1.0f / a : 0.0f;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Sign( q3r32 a )
{
	if ( a >= q3r32( 0.0 ) )
	{
		return q3r32( 1.0 );
	}

	else
	{
		return q3r32( -1.0 );
	}
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Abs( q3r32 a )
{
	if ( a < q3r32( 0.0 ) )
		return -a;

	return a;
}

//--------------------------------------------------------------------------------------------------
inline q3i32 q3Min( q3i32 a, q3i32 b )
{
	if ( a < b )
		return a;

	return b;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Min( q3r32 a, q3r32 b )
{
	if ( a < b )
		return a;

	return b;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Max( q3r32 a, q3r32 b )
{
	if ( a > b )
		return a;

	return b;
}

//--------------------------------------------------------------------------------------------------
inline q3i32 q3Max( q3i32 a, q3i32 b )
{
	if ( a > b )
		return a;

	return b;
}

//--------------------------------------------------------------------------------------------------
inline q3u8 q3Max( q3u8 a, q3u8 b )
{
	if ( a > b )
		return a;

	return b;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Clamp01( q3r32 val )
{
	if ( val >= q3r32( 1.0 ) )
		return 1.0;

	if ( val <= q3r32( 0.0 ) )
		return 0.0;

	return val;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Clamp( q3r32 min, q3r32 max, q3r32 a )
{
	if ( a < min )
		return min;

	if ( a > max )
		return max;

	return a;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3Lerp( q3r32 a, q3r32 b, q3r32 t )
{
	return a * (q3r32( 1.0 ) - t) + b * t;
}

//--------------------------------------------------------------------------------------------------
inline const q3Vec3 q3Lerp( const q3Vec3& a, const q3Vec3& b, q3r32 t )
{
	return a * (q3r32( 1.0 ) - t) + b * t;
}

//--------------------------------------------------------------------------------------------------
inline q3r32 q3RandomFloat( q3r32 l, q3r32 h )
{
	q3r32 a = q3r32( rand( ) );
	a /= q3r32( RAND_MAX );
	a = (h - l) * a + l;

	return a;
}

//--------------------------------------------------------------------------------------------------
inline q3i32 q3RandomInt( q3i32 low, q3i32 high )
{
	return (rand( ) % (high - low + 1) + low);
}
