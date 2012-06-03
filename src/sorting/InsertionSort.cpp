#include <iostream>
#include <inttypes.h>
#include "Sort.h"

using namespace algorithms;

void InsertionSort::sort(void **array, 
                         int n,
                         int (*cmp)(const void *, const void *))
{
    for (int i=1; i<n; i++) {
        int j = i - 1;
        void *value = array[i];
        while (j >= 0 && cmp(array[j], value) > 0)
        {
            array[j+1] = array[j];
            j--;
        }
        
        array[j+1] = value;
    }
}
