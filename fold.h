#ifndef ___iter_FOLD_H_INCLUDED___
    #define ___iter_FOLD_H_INCLUDED___

    #include "binop.h"

    /**** Functions: ****/
    void *ITER_left_fold(ITER_iterator_t *iterator, 
        ITER_binary_operation operation);
    void *ITER_right_fold(ITER_iterator_t *iterator, 
        ITER_binary_operation operation, size_t num_of_elements);
    void *ITER_left_fold_1(ITER_iterator_t *iterator, 
        ITER_binary_operation operation);
    void *ITER_right_fold_1(ITER_iterator_t *iterator, 
        ITER_binary_operation operation, size_t num_of_elements);
#endif
