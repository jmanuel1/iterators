/******* Pretty names for the iterator API. *******/
#ifndef ___ITER_PRETTY_INCLUDED___
    #define ___ITER_PRETTY_INCLUDED___

    /* Project includes. */
    #include "iteratee.h"
    #include "iterator.h"
    #include "fold.h"

    #define iteratee_return_type(type) ITER_iteratee_return_val_t(type)
    typedef ITER_iteratee_state_t iteratee_state_type;
    #define iteratee_data_type(type) ITER_iteratee_data_t(type)
    typedef ITER_iteratee_indicator_t iteratee_indicator_type;
    #define iteratee(name, type) ITER_iteratee(name, type)
    #define call_iteratee(iteratee, indicator, data) ITER_call_iteratee( \
        iteratee, \
        indicator, \
        data \
        )

    typedef ITER_for_body_ret_val_t for_body_return_type;
    typedef ITER_for_body_t for_body;
    #define iterator(type) ITER_iterator_t(type)
    #define iter(iterable) ITER_new_iterator(iterable)
    #define for_each(iter, type, body, state) ITER_for_each( \
        iter, \
        type, \
        body, \
        state \
        )

    #define left_fold(iter, type, op, def, ret) ITER_left_fold( \
        iter, \
        type, \
        op, \
        def, \
        ret \
        )
    #define right_fold(iter, type, op, def, ret, err, size) ITER_right_fold( \
        iter, \
        type, \
        op, \
        def, \
        ret, \
        err, \
        size \
        )
    #define left_fold_1(iter, type, op, ret) ITER_left_fold_1( \
        iter, \
        type, \
        op, \
        ret \
        )
    #define right_fold_1(iter, type, op, ret, err, size) ITER_right_fold_1( \
        iter, \
        type, \
        op, \
        ret, \
        err, \
        size \
        )
#endif
