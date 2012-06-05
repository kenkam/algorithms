#ifndef algorithms_Sort_h
#define algorithms_Sort_h

#include "ISort.h"

using namespace std;

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
        const string getName() { return "InsertionSort";}
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
    
    class MedianSort: public BaseSort
    {
    private:
        void doMedianSort(void **array,
                        int (*cmp)(const void *, const void *),
                        int left,
                        int right);
        int partition(void **array,
                       int (*cmp)(const void *, const void *),
                       int left,
                       int right,
                       int pivotIndex);
        int selectKth(void **array,
                       int (*cmp)(const void *, const void *),
                       int k,
                       int left,
                       int right);
    public:
        const string getName() { return "MedianSort";}
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
}

#endif
