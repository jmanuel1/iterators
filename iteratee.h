#ifndef ___ITER_ITERATEE_H_INCLUDED___
    #define ___ITER_ITERATEE_H_INCLUDED___

    /**** Types: ****/

    /* Type-generic iteratee return value type. */
    #define ITER_iteratee_return_val_t(data_type) \
        struct \
        { \
            ITER_iteratee_state_t state; \
            data_type ret; \
        }

    /* Iteratee state. */
    typedef enum
    {
        ITER_ITERATEE_STOP,
        ITER_ITERATEE_CONTINUE,
        ITER_ITERATEE_ERROR
    } ITER_iteratee_state_t;

    /* Type to pass a value to an iteratee. */
    #define ITER_iteratee_data_t(data_type) \
        struct \
        { \
            ITER_iteratee_indicator_t indicator; \
            data_type data; \
        }

    /* Type to tell an iteratee whether there is data, no data available, or 
    the iteration process is finished. */
    typedef enum
    {
        ITER_ITERATEE_DATA,
        ITER_ITERATEE_NO_DATA,
        ITER_ITERATEE_FINISHED
    } ITER_iteratee_indicator_t;

    /**** Decorator macros. ****/

    /* Iteratee decorator. */
    #define ITER_iteratee(name, data_type) \
        ITER_iteratee_return_val_t(data_type) name( \
            ITER_iteratee_data_t(data_type) *data \
            )

    /**** Other macros. ****/
    #define ITER_call_iteratee(iteratee, indicator, data) iteratee( \
        {indicator, data} \
        )
#endif
