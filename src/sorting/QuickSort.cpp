#include <iostream>
#include <cstdlib>
#include "Sort.h"

using namespace algorithms;
using namespace std;

InsertionSort* QuickSort::InsertionSorter = new InsertionSort;

/// An adaptive QuickSort implementation that uses InsertionSort for subarrays
/// that is smaller than a smaller given size. This is a worst-case quadratic-
/// time algorithm.
QuickSort::~QuickSort()
{
    delete QuickSort::InsertionSorter;
}

void QuickSort::sort(void **array, 
                     int n,
                     int (*cmp)(const void *, const void *))
{
    int left = 0;
    int right = n-1;
    doQuickSort(array, cmp, left, right);
}

/// Recursive implementation of QuickSort
void QuickSort::doQuickSort(void **array,
                            int (*cmp)(const void *, const void *),
                            int left,
                            int right)
{
    if (right <= left) return;

    // pick a random pivot
    int pivot = rand() % (right-left) + left;
    pivot = partition(array, cmp, left, right, pivot);
    
    if (pivot-1-left <= minSize)
    {
        InsertionSorter->doInsertionSort(array, left, pivot-1, cmp);
    }
    else 
    {
        doQuickSort(array, cmp, left, pivot-1);
    }
    
    if (right-pivot-1 <= minSize)
    {
        InsertionSorter->doInsertionSort(array, pivot+1, right, cmp);
    }
    else 
    {
        doQuickSort(array, cmp, pivot+1, right);
    }
}
