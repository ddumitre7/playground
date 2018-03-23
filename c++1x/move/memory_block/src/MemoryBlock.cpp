/*
 * MemoryBlock.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: dan
 */

#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(size_t length)
      : _length{length},
		_data{new int[length]}
{
	std::cout << "In MemoryBlock(size_t). Length = "
                << _length << "." << std::endl;
}

// Destructor.
MemoryBlock::~MemoryBlock()
{
	std::cout << "In ~MemoryBlock(). Length = "
                << _length << ".";

    if (_data != nullptr)
    {
    	std::cout << " Deleting resource.";
        // Delete the resource.
        delete[] _data;
    }

    std::cout << std::endl;
}


// Copy constructor.
MemoryBlock::MemoryBlock(const MemoryBlock& other)
      : _length{other._length},
      _data{new int[other._length]}
   {
         std::cout << "In MemoryBlock(const MemoryBlock&). Length = "
                   << other._length << ". Copying resource." << std::endl;

         std::copy(other._data, other._data + _length, _data);
      }

// Copy assignment operator.
MemoryBlock& MemoryBlock::operator=(const MemoryBlock& other)
{
     std::cout << "In operator=(const MemoryBlock&). Length = "
               << other._length << ". Copying resource." << std::endl;

     if (this != &other)
     {
            // Free the existing resource.
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
     }
     return *this;
}


// Move constructor.
MemoryBlock::MemoryBlock(MemoryBlock&& other)
   : _length{0}, _data{nullptr}
{
   std::cout << "In MemoryBlock(MemoryBlock&&). Length = "
             << other._length << ". Moving resource." << std::endl;

   // Copy the data pointer and its length from the
   // source object.
   _data = other._data;
   _length = other._length;

   // Release the data pointer from the source object so that
   // the destructor does not free the memory multiple times.
   other._data = nullptr;
   other._length = 0;
}

// Move assignment operator.
MemoryBlock& MemoryBlock::operator=(MemoryBlock&& other)
{
   std::cout << "In operator=(MemoryBlock&&). Length = "
             << other._length << "." << std::endl;

   if (this != &other)
   {
      // Free the existing resource.
      delete[] _data;

      // Copy the data pointer and its length from the
      // source object.
      _data = other._data;
      _length = other._length;

      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other._data = nullptr;
      other._length = 0;
   }
   return *this;
}

