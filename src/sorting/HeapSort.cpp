#include <iostream>
#include <assert.h>
#include "Sort.h"

using namespace algorithms;

/// HeapSort first heapifies an array, then uses the heap property to sort the
/// array in place. The array is sorted by growing a sorted subarray positioned
/// at the end of the array A[i:n). The root node is swapped with the ith 
/// element as i decreases. This sort works because the root element is always
/// guaranteed to be the largest in value in the heap A[0:i) and smaller than
/// the values in A[i:n).
void HeapSort::sort(void **array, 
                    int n, 
                    int (*cmp)(const void *, const void *))
{
    buildHeap(array, n, cmp);
    for (int i=n-1; i>=1; i--)
    {
        void *tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        heapify(array, 0, i, cmp);
    }
}

/// Makes array a valid heap that obeys the heap property.
void HeapSort::buildHeap(void **array, 
                         int n,
                         int (*cmp)(const void *, const void *))
{
    for (int i=n/2-1; i>=0; i--)
    {
        heapify(array, i, n, cmp);
    }
    assert(HeapSort::isHeap(array, n, cmp));
}

/// Given an array and an index, ensures that array comforms to the heap 
/// property. In other words, the leaf values at 2*index+1, 2*index+2 are
/// smaller than the parent node's value.
void HeapSort::heapify(void **array, 
                       int index,
                       int n,
                       int (*cmp)(const void *, const void *))
{
    int left = 2*index+1;
    int right = 2*index+2;
    int largest;
    
    if (left < n && cmp(array[left], array[index]) > 0)
    {
        largest = left;
    }
    else 
    {
        largest = index;
    }
    
    if (right < n && cmp(array[right], array[largest]) > 0)
    {
        largest = right;
    }
    
    if (largest != index)
    {
        void *tmp = array[index];
        array[index] = array[largest];
        array[largest] = tmp;
        heapify(array, largest, n, cmp);
    }
}

/// Returns true if the array is a heap.
bool HeapSort::isHeap(void **array,
                      int n,
                      int (*cmp)(const void *, const void *))
{
    for (int i=n/2-1; i>=0; i--)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        
        if (left < n && cmp(array[left], array[i]) > 1)
        {
            return false;
        }
        if (right < n && cmp(array[right], array[i]) > 1)
        {
            return false;
        }
    }
    return true;
}
