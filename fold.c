/* Project includes. */
#include "iterator.h"
#include "fold.h"
#include "binop.h"

void *ITER_left_fold(ITER_iterator_t *iterator, 
    ITER_binary_operation operation)
{
    void *item, *ret = NULL;
    int index = 0;
    bool terminate;

    while (true)
    {
        item = iterator->item(index, iterator->iterable, &terminate);
        if (terminate)
        {
            break;
        }
        ret = operation(ret, item);
        index++;
    }

    return ret;
}

void *ITER_right_fold(ITER_iterator_t *iterator, 
    ITER_binary_operation operation, size_t num_of_elements)
{
    void *item, *ret = NULL;
    int index = num_of_elements;
    bool terminate = false;

    while (--index != -1)
    {
        item = iterator->item(index, iterator->iterable, &terminate);
        ret = operation(ret, item);
    }

    return ret;
}

void *ITER_left_fold_1(ITER_iterator_t *iterator, 
    ITER_binary_operation operation)
{
    void *item, *ret;
    int index = 0;
    bool terminate = false;

    /* Assume the iterable is not empty. */
    ret = iterator->item(0, iterator->iterable, &terminate);

    while (true)
    {
        item = iterator->item(index, iterator->iterable, &terminate);
        if (terminate)
        {
            break;
        }
        ret = operation(ret, item);
        index++;
    }

    return ret;
}

void *ITER_right_fold_1(ITER_iterator_t *iterator, 
    ITER_binary_operation operation, size_t num_of_elements)
{
    void *item, *ret = NULL;
    int index = num_of_elements - 1;
    bool terminate = false;

    /* Assume a non-empty iterable. */
    ret = iterator->item(index, iterator->iterable, &terminate);

    while (--index != -1)
    {
        item = iterator->item(index, iterator->iterable, &terminate);
        ret = operation(ret, item);
    }

    return ret;
}
