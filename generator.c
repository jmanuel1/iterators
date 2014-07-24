/******* Generators *******/
/* Standard includes: */
#include <stdbool.h>

/* Project includes: */
#include "generator.h"
#include "iterator.h"

/**** Macros: ****/
/* Start defining a generator.
This is pretty much what Python calls a "decorator." */
#define ITER_generator(return_type, identifier) \
    void *identifier( \
        int __step__, \
        void ***__state__, \
        bool *__terminate__, \
        void **args \
        )

/* Declare a generator, but don't define it (prototyping). Arguments are the 
same as for the ITER_generator macro. */
#define ITER_prototype_generator(identifier) \
    void *identifier( \
        int __step__, \
        void ***__state__, \
        bool *__terminate__, \
        void **args \
        ); /* This ends with a semi-colon because it is a function protoype. */

/* THIS SHOULD BE USED ONLY WITHIN A GENERATOR. The argument should complete an 
expression that starts with "__step__". Examples: "== 5", ">= 6". The resulting 
expression must be an integer expression suitable for use in an if statement.

Example use:
ITER_declare_step(< 5)
{
    return 3.14;
} */
#define ITER_declare_step(condition) if (__step__ condition)

/**** Functions: ****/

/* THIS SHOULD BE USED ONLY WITHIN A GENERATOR. This function allocates memory 
for the __state__ variable of a generator. The argument should be the size of 
the __state__, in bytes, as an integer. The __state__ variable is 
returned. The generator need not free its __state__ itself. */
void **ITER_allocate_state(void ***__state__, size_t size)
{
    *__state__ = (void **) malloc(size);
    return *__state__;
}

/* Make a ITER_iterator_t object out of a generator. */
ITER_iterator_t *ITER_iterator_from_generator(
    void *(*generator)(int, void ***, bool *, void **), void **args
    )
{
    ITER_iterator_t iterator;
