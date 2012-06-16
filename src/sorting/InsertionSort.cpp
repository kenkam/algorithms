#include <iostream>
#include "Sort.h"

using namespace algorithms;
using namespace std;

void InsertionSort::sort(void **array, 
                         int n,
                         int (*cmp)(const void *, const void *))
{
    doInsertionSort(array, 0, n-1, cmp);
}

void InsertionSort::doInsertionSort(void **array,
                                    int left,
                                    int right,
                                    int (*cmp)(const void *, const void *))
{
    for (int i=left+1; i<right+1; i++) {
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
