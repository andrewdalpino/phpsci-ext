/*
  +----------------------------------------------------------------------+
  | PHPSci CArray                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2018 PHPSci Team                                       |
  +----------------------------------------------------------------------+
  | Licensed under the Apache License, Version 2.0 (the "License");      |
  | you may not use this file except in compliance with the License.     |
  | You may obtain a copy of the License at                              |
  |                                                                      |
  |     http://www.apache.org/licenses/LICENSE-2.0                       |
  |                                                                      |
  | Unless required by applicable law or agreed to in writing, software  |
  | distributed under the License is distributed on an "AS IS" BASIS,    |
  | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or      |
  | implied.                                                             |
  | See the License for the specific language governing permissions and  |
  | limitations under the License.                                       |
  +----------------------------------------------------------------------+
  | Authors: Henrique Borba <henrique.borba.dev@gmail.com>               |
  +----------------------------------------------------------------------+
*/

#ifndef PHPSCI_EXT_ARITHMETIC_H
#define PHPSCI_EXT_ARITHMETIC_H

#include "../kernel/buffer/memory_manager.h"

void add(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void add_carray_0d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void add_carray_1d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void add_carray_2d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);

void subtract(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void subtract_carray_0d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void subtract_carray_1d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
void subtract_carray_2d(MemoryPointer * ptr_a, MemoryPointer * ptr_b, MemoryPointer * rtn_ptr, int * size_x, int * size_y);
#endif //PHPSCI_EXT_ARITHMETIC_H
