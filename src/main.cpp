#include <cstdlib>
#include <iostream>
#include "Sort.h"

#define     NUM_ELEMS   100

using namespace algorithms;
using namespace std;

int ** make_unordered_array()
{
    int** arrPtr = new int *[NUM_ELEMS];
    
    for (int i=0; i<NUM_ELEMS; i++)
    {
        arrPtr[i] = new int(i+1);
    }
    
    // randomly make the array unordered by looping through the array once and 
    // swapping with a random element
    for (int i=0; i<NUM_ELEMS; i++)
    {
        int pos = rand() % NUM_ELEMS;
        int *value = arrPtr[pos];
        arrPtr[pos] = arrPtr[i];
        arrPtr[i] = value;
    }
    
    return arrPtr;
}

void free_array(int ** arr)
{
    for (int i=0; i<NUM_ELEMS; i++)
    {
        delete arr[i];
    }
    
    delete [] arr;
}

int int_cmp(const void *a, const void *b)
{
    return *((int *) a) > *((int *) b);
}

int main(int argc, const char * argv[])
{
    ISort *sorter = new InsertionSort;
    int** arrPtr = new int *[NUM_ELEMS];
    
    arrPtr = make_unordered_array();
        
    cout << "Before sorting" << endl;
    for (int i=0; i<NUM_ELEMS; i++) {
        cout << *arrPtr[i] << endl;
    }
    
    sorter->sort((void **) arrPtr, NUM_ELEMS, &int_cmp);
    
    cout << "After sorting" << endl;
    for (int i=0; i<NUM_ELEMS; i++) {
        cout << *arrPtr[i] << endl;
    }
    
    free_array(arrPtr);
    return 0;
}

