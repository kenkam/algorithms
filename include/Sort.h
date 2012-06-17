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
        virtual ~BaseSort() {};
    };
    
    class InsertionSort: public BaseSort
    {
    public:
        const string getName() { return "InsertionSort";}
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
        void doInsertionSort(void **array,
                             int left,
                             int right,
                             int (*cmp)(const void *, const void *));
    };
    
    class MedianSort: public BaseSort
    {
    private:
        void doMedianSort(void **array,
                          int (*cmp)(const void *, const void *),
                          int left,
                          int right);
    public:
        const string getName() { return "MedianSort";}
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
    
    class QuickSort: public BaseSort
    {
    private:
        const static int minSize = 4;
        static InsertionSort *InsertionSorter;
        void doQuickSort(void **array,
                         int (*cmp)(const void *, const void *),
                         int left,
                         int right);
    public:
        ~QuickSort();
        const string getName() { return "QuickSort";}
        void sort(void **array, 
                  int n,
                  int (*cmp)(const void *, const void *));
    };
    
    class HeapSort: public BaseSort
    {
    private:
        void heapify(void **array,
                     int index,
                     int n,
                     int (*cmp)(const void *, const void *));
        void buildHeap(void **array,
                       int n,
                       int (*cmp)(const void *, const void *));
    public:
        const string getName() { return "HeapSort";}
        static bool isHeap(void **array,
                           int n,
                           int (*cmp)(const void *, const void *));
        void sort(void **array,
                  int n,
                  int (*cmp)(const void *, const void *));
    };
    
    /// In linear time, group the array around a pivot such that elements smaller 
    /// than pivot is to the left of the it and elements larger than the pivot
    /// to the right of it, returning the correct location of the pivot within the
    /// array.
    int partition(void **array, 
                  int (*cmp)(const void *, const void *),
                  int left,
                  int right,
                  int pivotIndex);
    
    /// Selects the kth element in the array and returns it, partitioning the array
    /// such that smaller elements are placed before k and larger elements are 
    /// placed after.
    int selectKth(void **array, 
                  int (*cmp)(const void *, const void *), 
                  int k, 
                  int left, 
                  int right);
}

#endif
