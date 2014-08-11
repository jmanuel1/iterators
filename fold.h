#ifndef ___ITER_FOLD_H_INCLUDED___
    #define ___ITER_FOLD_H_INCLUDED___

    /* Standard includes. */
    #include <stdbool.h>

    /* Project includes. */
    #include "iterator.h"

    /* Type-generic left-fold without void pointers (no-void* implementation) */
    #define ITER_left_fold(iterator, elem_type, operation, default, result) \
        do \
        { \
            elem_type item, ret = default; \
            bool terminate; \
            while (true) \
            { \
                /* Use iterator.next() to support generators. */ \
                item = iterator.next(iterator.iterable, &terminate); \
                if (terminate) \
                { \
                    break; \
                } \
                ret = operation(ret, item); \
            } \
            result = ret; /* Assign the result to a variable in the enclosing \
            scope. */ \
        } while (false) /* No semi-colon. */

    #define ITER_right_fold(iterator, elem_type, operation, default, result, error, \
        num_of_elements) \
        do \
        { \
            elem_type item, ret = default; \
            int index = num_of_elements; \
            bool terminate; \
            while (--index != -1) \
            { \
                /* Use iterator.item(); generators don't support this. */ \
                if (iterator.item == NULL) \
                { \
                    error = true; /* Throw an error. */ \
                    break; \
                } \
                item = iterator.item(index, iterator.iterable, &terminate); \
                ret = operator(ret, item); \
            } \
            if (error) \
            { \
                break; \
            } \
            result = ret; \
        } while (false) /* No semi-colon. */

    #define ITER_left_fold_1(iterator, elem_type, operation, result) \
        do \
        { \
            elem_type item, ret; \
            int index = 0; \
            bool terminate = false; \
            /* Assume the iterable is not empty. */ \
            ret = iterator.next(iterator.iterable, &terminate); \
            while (true) \
            { \
                item = iterator.next(iterator.iterable, &terminate); \
                if (terminate) \
                { \
                    break; \
                } \
                ret = operation(ret, item); \
            } \
            result = ret; \
        }

    #define ITER_right_fold_1(iterator, elem_type, operation, result, \
        error, num_of_elements) \
        do \
        { \
            elem_type item, ret; \
            int index = num_of_elements - 1; \
            bool terminate = false; \
            /* Check for iterator.item() */ \
            if (iterator.item == NULL) \
            { \
                error = true; \
                break; \
            } \
            /* Assume a non-empty iterable. */ \
            ret = iterator.item(index, iterator.iterable, &terminate); \
            while (--index != -1) \
            { \
                item = iterator.item(index, iterator.iterable, &terminate); \
                ret = operation(ret, item); \
            } \
            return ret; \
        }
#endif
