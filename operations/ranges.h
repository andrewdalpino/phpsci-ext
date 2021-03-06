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
#include "../phpsci.h"
#include "../kernel/carray/carray.h"

#ifndef PHPSCI_EXT_RANGES_H
#define PHPSCI_EXT_RANGES_H
#include "../kernel/buffer/memory_manager.h"

void logspace(MemoryPointer * ptr, double start, double stop, int num, double base);
void arange(MemoryPointer * new_ptr, double start, double stop, double step, int * width);
void linspace(MemoryPointer * ptr, double start, double stop, int num);
#endif //PHPSCI_EXT_RANGES_H
