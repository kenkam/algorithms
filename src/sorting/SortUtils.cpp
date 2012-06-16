#include <iostream>
#include "Sort.h"

namespace algorithms {
    /// In linear time, group the array around a pivot such that elements smaller 
    /// than pivot is to the left of the it and elements larger than the pivot
    /// to the right of it, returning the correct location of the pivot within the
    /// array.
    int partition(void **array, 
                  int (*cmp)(const void *, const void *),
                  int left,
                  int right,
                  int pivotIndex)
    {
        // move pivot to the end of the array
        void *tmp = array[right];
        array[right] = array[pivotIndex];
        array[pivotIndex] = tmp;
        
        int store = left;
        for (int i=left; i<right; i++) {
            if (cmp(array[i], array[right]) <= 0)
            {
                tmp = array[store];
                array[store] = array[i];
                array[i] = tmp;
                store++;    
            }    
        }
        
        tmp = array[store];
        array[store] = array[right];
        array[right] = tmp;
        
        return store;
    }

    /// Selects the kth element in the array and returns it, partitioning the array
    /// such that smaller elements are placed before k and larger elements are 
    /// placed after.
    int selectKth(void **array, 
                  int (*cmp)(const void *, const void *), 
                  int k, 
                  int left, 
                  int right)
    {
        int idx = right;
        idx = partition(array, cmp, left, right, idx);
        
        // 3 cases: k is the median value
        if (k == idx+1-left) return idx;
        
        // k is smaller than the pivot index
        if (k < idx+1-left)
        {
            return selectKth(array, cmp, k, left, idx-1);
        } else 
        {
            return selectKth(array, cmp, k - (idx-left+1), idx+1, right);
        }
    }
}
