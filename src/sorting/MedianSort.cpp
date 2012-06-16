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




