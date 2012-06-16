#include <cstdlib>
#include <iostream>
#include "Runner.h"

using namespace algorithms;
using namespace std;

void ** make_unordered_array()
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
    
    return (void **) arrPtr;
}

void free_array(void ** arr)
{
    for (int i=0; i<NUM_ELEMS; i++)
    {
        delete (int *) arr[i];
    }
    
    delete [] arr;
}

int int_cmp(const void *a, const void *b)
{
    return *((int *) a) > *((int *) b);
}

int main(int argc, const char * argv[])
{
    Runner *runner = new Runner;
    runner->run(&int_cmp, &make_unordered_array, &free_array);
    
    delete runner;
    return 0;
}

