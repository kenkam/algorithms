#ifndef algorithms_Sort_h
#define algorithms_Sort_h

#include "ISort.h"

namespace algorithms {
    class InsertionSort: public ISort
    {
    public:
        virtual void sort(void **array, 
                          int n,
                          int (*cmp)(const void *, const void *));
    };
}

#endif
