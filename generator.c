/******* Generators *******/
/* Standard includes: */
#include <stdbool.h>

/* Project includes: */
#include "generator.h" /* This should include <string.h>. INCLUDE IT. */
#include "iterator.h"

/**** Macros: ****/
/* Start defining a generator.
This is pretty much what Python calls a "decorator." */
#define ITER_generator(return_type, identifier) \
    return_type identifier( \
        void ***__state__, \
        bool *__terminate__, \
        void **args \
        )

/**** Functions: ****/

/* THIS SHOULD BE USED ONLY WITHIN A GENERATOR. This function allocates memory 
for the __state__ variable of a generator. The argument should be the size of 
the __state__, as a number of pointers to void, as an integer. The __state__ 
variable is returned. The generator need not free its __state__ itself. */
void **ITER_allocate_state(void ***__state__, size_t size)
{
    *__state__ = (void **) malloc(size * sizeof(void *));
    return *__state__;
}

/* Make a ITER_iterator_t(elem_type) object out of a generator. */
#define ITER_iterator_from_generator(elem_type, generator_func, args) \
    do { \
        ITER_iterator_t(elem_type) iterator; \
        
