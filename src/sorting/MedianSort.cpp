#include <iostream>
#include "Sort.h"

using namespace algorithms;

/// Median sort implemented as described by O'Reilly's Algorithms In A Nutshell.
/// A median element is selected as a pivot where smaller elements on the right
/// of this pivot is swapped with larger elements on the left. However, the 
/// book presents an implementation that works _backwards_, ie. first, recursively
/// partition the array such that the returned pivot location is where the
/// median value is expected (selectKth), then apply this to the left and right
/// of the median value.
void MedianSort::sort(void **array, 
                      int n,
                      int (*cmp)(const void *, const void *))
{
    int left = 0;
    int right = n-1;
    doMedianSort(array, cmp, left, right);
}

/// Recursive implementation of median sort
void MedianSort::doMedianSort(void **array,
                              int (*cmp)(const void *, const void *),
                              int left,
                              int right)
{
    if (right <= left) return;
    int mid = (right-left+1) / 2;
    selectKth(array, cmp, mid+1, left, right);
    
    doMedianSort(array, cmp, left, left+mid-1);
    doMedianSort(array, cmp, left+mid+1, right);
}

/// Selects the kth element in the array and returns it, partitioning the array
/// such that smaller elements are placed before k and larger elements are 
/// placed after.
int MedianSort::selectKth(void **array, 
                          int (*cmp)(const void *, const void *), 
                          int k, 
                          int left, 
                          int right)
{
    int idx = right;
    idx = partition(array, cmp, left, right, idx);
    
    // 3 cases: k is the he median value
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

/// In linear time, group the array around a pivot such that elements smaller 
/// than pivot is to the left of the it and elements larger than the pivot
/// to the right of it, returning the correct location of the pivot within the
/// array.
int MedianSort::partition(void **array, 
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
