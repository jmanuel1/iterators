#ifndef ___ITER_ITERATOR_H_INCLUDED___
    #define ___ITER_ITERATOR_H_INCLUDED___

    /* Standard includes. */
    #include <stdbool.h>

    /* Enum to represent values returned by a for-each body. */
    typedef enum
    {
        ITER_CONTINUE;
        ITER_BREAK;
    } ITER_for_body_ret_val_t;

    /* 
    Type to represent for-each bodies. The state argument should be an array 
    of pointers to void representing state to be passed to the for-each body. 
    */
    typedef ITER_for_body_ret_val_t 
        (*ITER_for_body_t)(void *item, void *state[]);

    /* Type-generic way to represent iterators. */
    #define ITER_iterator_t(elem_type) \
        struct \
        { \
            void *iterable; \
            /* \
            For generators (if such a thing is implemented), .item is NULL. \
            */ \
            elem_type (*item)(int index, void *iterable, bool *terminate); \
            elem_type (*next)(void *iterable, bool *terminate); \
        }

    /* Type-generic solution to create iterators with malloc()ating them first. */
    #define ITER_new_iterator(iterable) \
        {(void *) &iterable, iterable.__item__, iterable.__next__}

    /* Type-generic for-each. */
    #define ITER_for_each(iterator, elem_type, body, state) \
        do \
        { \
            elem_type item; \
            bool terminate, break_now; \
            while (true) \
            { \
                /* Use iterator.next() to support generators. */ \
                item = iterator.next(iterator.iterable, &terminate); \
                break_now = (body(item, state) == ITER_BREAK); \
                if (terminate || break_now) \
                { \
                    break; \
                } \
            } \
        } while (false) /* No semi-colon. */
#endif
