#ifndef ___iter_ITERATOR_H_INCLUDED___
    #define ___iter_ITERATOR_H_INCLUDED___

    #include <stdbool.h>

    /* Enum to represent values returned by a for-each body. */
    typedef enum
    {
        ITER_CONTINUE;
        ITER_BREAK;
    } ITER_for_body_ret_val;

    /* Type to represent functions that return items from an iterable. */
    typedef void *(*ITER_item_func_t)(int index, void *iterable, 
        bool *terminate);

    /* 
    Type to represent functions that return the next item from an iterable. 
    */
    typedef void *(*ITER_next_func_t)(void *iterable, bool *terminate);

    /* Type to represent for-each bodies. */
    typedef ITER_for_body_ret_val (*ITER_for_body_t)(void *item, void **args);

    /* Type to represent iterators. */
    typedef struct 
    {
        void *iterable;
        ITER_item_func_t item;
        ITER_next_func_t next;
    } ITER_iterator_t;

    /**** Functions: ****/

    /* Return a new iterator. */
    ITER_iterator_t *ITER_new_iterator(void *iterable, ITER_item_func_t item);
    /* Free the memory taken by an iterator. */
    void ITER_del_iterator(ITER_iterator_t **iterator);
    /* Call func on every element returned by iterator in order. */
    void ITER_for_each(ITER_iterator_t *iterator, ITER_for_body_t body, 
        void **func_args);
#endif
