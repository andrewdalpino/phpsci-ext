#ifndef PHPSCI_EXT_COMMON_H
#define PHPSCI_EXT_COMMON_H

#include "../carray.h"

#  define CARRAY_LONGLONG_SUFFIX(x)  (x##L)
#  define CARRAY_ULONGLONG_SUFFIX(x) (x##UL)

/*
 * numarray-style bit-width typedefs
 */
#define CARRAY_MAX_INT8 127
#define CARRAY_MIN_INT8 -128
#define CARRAY_MAX_UINT8 255
#define CARRAY_MAX_INT16 32767
#define CARRAY_MIN_INT16 -32768
#define CARRAY_MAX_UINT16 65535
#define CARRAY_MAX_INT32 2147483647
#define CARRAY_MIN_INT32 (-CARRAY_MAX_INT32 - 1)
#define CARRAY_MAX_UINT32 4294967295U
#define CARRAY_MAX_INT64 CARRAY_LONGLONG_SUFFIX(9223372036854775807)
#define CARRAY_MIN_INT64 (-CARRAY_MAX_INT64 - CARRAY_LONGLONG_SUFFIX(1))
#define CARRAY_MAX_UINT64 CARRAY_ULONGLONG_SUFFIX(18446744073709551615)
#define CARRAY_MAX_INT128 CARRAY_LONGLONG_SUFFIX(85070591730234615865843651857942052864)
#define CARRAY_MIN_INT128 (-CARRAY_MAX_INT128 - CARRAY_LONGLONG_SUFFIX(1))
#define CARRAY_MAX_UINT128 CARRAY_ULONGLONG_SUFFIX(170141183460469231731687303715884105728)
#define CARRAY_MAX_INT256 CARRAY_LONGLONG_SUFFIX(57896044618658097711785492504343953926634992332820282019728792003956564819967)
#define CARRAY_MIN_INT256 (-CARRAY_MAX_INT256 - CARRAY_LONGLONG_SUFFIX(1))
#define CARRAY_MAX_UINT256 CARRAY_ULONGLONG_SUFFIX(115792089237316195423570985008687907853269984665640564039457584007913129639935)
#define CARRAY_MIN_DATETIME CARRAY_MIN_INT64
#define CARRAY_MAX_DATETIME CARRAY_MAX_INT64
#define CARRAY_MIN_TIMEDELTA CARRAY_MIN_INT64
#define CARRAY_MAX_TIMEDELTA CARRAY_MAX_INT64


CArray * new_array_for_sum(CArray *ap1, CArray *ap2, CArray* out,
                           int nd, int dimensions[], int typenum, CArray **result);

#endif //PHPSCI_EXT_COMMON_H