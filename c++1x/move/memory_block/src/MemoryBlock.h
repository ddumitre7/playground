/*
 * MemoryBlock.h
 *
 *  Created on: Mar 7, 2018
 *      Author: dan
 */

#ifndef MEMORYBLOCK_H_
#define MEMORYBLOCK_H_

#include <iostream>
#include <algorithm>

class MemoryBlock
{
public:

   // Simple constructor that initializes the resource.
   explicit MemoryBlock(size_t length=0);

   // Destructor.
   ~MemoryBlock();


   // Copy constructor.
   MemoryBlock(const MemoryBlock& other);

   // Copy assignment operator.
   MemoryBlock& operator=(const MemoryBlock& other);


   MemoryBlock(MemoryBlock&& other);
   MemoryBlock& operator=(MemoryBlock&& other);

   // Retrieves the length of the data resource.
   size_t Length() const
   {
	   return _length;
   }

   private:
      size_t _length; // The length of the resource.
      int* _data; // The resource.
   };



#endif /* MEMORYBLOCK_H_ */
