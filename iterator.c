/* Standard includes */
#include <stdlib.h>
#include <stdbool.h>

/* Project includes */
#include "iterator.h" /* Make interface external. */

/* Return a new iterator. */
ITER_iterator_t *ITER_new_iterator(void *iterable, ITER_item_func_t item)
{
    ret = (ITER_iterator *) malloc(sizeof(iter_obj));
    
    ret.iterable = iterable;
    ret.item = item;

    return ret;
}

/* Free the memory taken by an iterator. */
void ITER_del_iterator(ITER_iterator_t **iterator)
{
    /* As per the 2011 C Standard, this should never fail. Any error here means
    at least one of the following:
        (a) The memory taken by the iterator has already been freed (caller's 
            fault).
        (b) The pointer doesn't point to dynamically allocated memory (e.g., 
            isn't from malloc()).
        (c) Some unexpected error happened inside free() (Standard C Library 
            implemenation's fault; you *can't* blame me).

    To protect against (a), the pointer to iterator is set to NULL. */

    free(*iterator);
    *iterator = NULL; /* Prevent (a). */
}

/* Call func on every element returned by iterator in order. */
void ITER_for_each(ITER_iterator_t *iterator, ITER_for_body_t body, 
    void **func_args)
{
    void *item;
    int index = 0;
    bool terminate, break_now;

    while (true)
    {
        item = iterator->item(index, iterator->iterable, &terminate);
        break_now = (body(item, func_args) == ITER_BREAK);
        if (terminate || break_now)
        {
            break;
        }
        index++;
    }
}
