//--------------------------------------------------------------------------------------------------
/**
@file	q3Memory.h

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

#ifndef Q3MEMORY_H
#define Q3MEMORY_H

#include <stdlib.h>

#include "q3Types.h"

//--------------------------------------------------------------------------------------------------
// Memory Macros
//--------------------------------------------------------------------------------------------------
inline void* q3Alloc( q3i32 bytes )
{
	return malloc( bytes );
}

inline void q3Free( void* memory )
{
	free( memory );
}

#define Q3_PTR_ADD( P, BYTES ) \
	((decltype( P ))(((q3u8 *)P) + (BYTES)))

//--------------------------------------------------------------------------------------------------
// q3Stack
//--------------------------------------------------------------------------------------------------

class q3Stack
{
private:
	struct q3StackEntry
	{
		q3u8 *data;
		q3i32 size;
	};

public:
	q3Stack( );
	~q3Stack( );

	void Reserve( q3u32 size );
	void *Allocate( q3i32 size );
	void Free( void *data );

private:
	q3u8* m_memory;
	q3StackEntry* m_entries;

	q3u32 m_index;

	q3i32 m_allocation;
	q3i32 m_entryCount;
	q3i32 m_entryCapacity;
	q3u32 m_stackSize;
};

//--------------------------------------------------------------------------------------------------
// q3Heap
//--------------------------------------------------------------------------------------------------
// 20 MB heap size, change as necessary
const q3i32 q3k_heapSize = 1024 * 1024 * 20;
const q3i32 q3k_heapInitialCapacity = 1024;

// Operates on first fit basis in attempt to improve cache coherency
class q3Heap
{
private:
	struct q3Header
	{
		q3Header* next;
		q3Header* prev;
		q3i32 size;
	};

	struct q3FreeBlock
	{
		q3Header* header;
		q3i32 size;
	};

public:
	q3Heap( );
	~q3Heap( );

	void *Allocate( q3i32 size );
	void Free( void *memory );

private:
	q3Header* m_memory;

	q3FreeBlock* m_freeBlocks;
	q3i32 m_freeBlockCount;
	q3i32 m_freeBlockCapacity;
};

//--------------------------------------------------------------------------------------------------
// q3PagedAllocator
//--------------------------------------------------------------------------------------------------
class q3PagedAllocator
{
	struct q3Block
	{
		q3Block* next;
	};

	struct q3Page
	{
		q3Page* next;
		q3Block* data;
	};

public:
	q3PagedAllocator( q3i32 elementSize, q3i32 elementsPerPage );
	~q3PagedAllocator( );

	void* Allocate( );
	void Free( void* data );

	void Clear( );

private:
	q3i32 m_blockSize;
	q3i32 m_blocksPerPage;

	q3Page *m_pages;
	q3i32 m_pageCount;

	q3Block *m_freeList;
};

#endif // Q3MEMORY_H
