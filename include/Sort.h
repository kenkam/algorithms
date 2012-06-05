#ifndef algorithms_Sort_h
#define algorithms_Sort_h

#include "ISort.h"

namespace algorithms {
    class BaseSort: public ISort
    {
    private:
        /// default comparison method
        static int cmp(const void *a, const void *b)
        {
            return a > b;
        }
    public:
        virtual void sort(void **array, 
                          int n,
                          int (*cmp)(const void *, const void *)) =0;

        /// sorting that uses the default comparison method
        virtual void sort(void **array,
                          int n)
        {
            sort(array, n, &BaseSort::cmp);
        }
    };
    
    class InsertionSort: public BaseSort
    {
    public:
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
    
    class MedianSort: public BaseSort
    {
    public:
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
}

#endif
