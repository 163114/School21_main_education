#include "s21_memmove.h"
#include "../s21_memcpy/s21_memcpy.h"
#include "../s21_common/s21_memcpy_forward_backward/s21_memcpy_forward_backward.h"

#include <stdlib.h>
#include <assert.h>

// static int is_destination_overlapping_from_left(
//     const unsigned char *destination, 
//     const unsigned char *source, 
//     s21_size_t size) {
//         return source - destination < (signed)size;
// }

// static int is_source_overlapping_from_left(
//     const unsigned char *destination, 
//     const unsigned char *source, 
//     s21_size_t size) {
//         return destination - source < (signed)size;
// }

// static int are_overlapping(
//     const unsigned char *destination, 
//     const unsigned char *source, 
//     s21_size_t size) {
    
//     return is_destination_overlapping_from_left(destination, source, size) ||
//            is_source_overlapping_from_left(destination, source, size);
// }

// static int are_not_overlapping(
//     const unsigned char *destination, 
//     const unsigned char *source, 
//     s21_size_t size) {
    
//     return !are_overlapping(destination, source, size);
// }

// void *s21_memmove(void *destination, const void *source, s21_size_t size) {
//     unsigned char *destination_uchar = (unsigned char*)destination;
//     const unsigned char *source_uchar = (const unsigned char*)source;

//     if (are_not_overlapping(destination_uchar, source_uchar, size))
//         return s21_memcpy(destination, source, size);

//     if (is_source_overlapping_from_left(
//         destination_uchar,
//         source_uchar,
//         size
//     ))
//         return __s21_memcpy_backward_uchar(
//             destination_uchar,
//             source_uchar,
//             size);
    
 
//     // if (is_destination_overlapping_from_left(
//     //     destination_uchar,
//     //     source_uchar,
//     //     size
//     // ))
//         return __s21_memcpy_forward_uchar(
//             destination_uchar,
//             source_uchar,
//             size);
// }

// This also works, but the code is repeated

void *s21_memmove(void *destination, const void *source, s21_size_t size) {
    unsigned char *destination_uchar = (unsigned char*)destination;
    const unsigned char *source_uchar = (const unsigned char*)source;

    unsigned char *destination_uchar_copy = malloc(size * sizeof(unsigned char));

    if (destination_uchar_copy == s21_NULL)
        exit(-1);

    for (s21_size_t index = 0ul; index < size; ++index)
        destination_uchar_copy[index] = source_uchar[index];

    for (s21_size_t index = 0ul; index < size; ++index)
        destination_uchar[index] = destination_uchar_copy[index];

    return destination_uchar_copy;
}
