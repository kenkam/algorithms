#include <iostream>
#include <vector>
#include "Runner.h"
#include "Sort.h"

using namespace algorithms;
using namespace std;

Runner::Runner()
{
    sorters.push_back(new InsertionSort);
    sorters.push_back(new MedianSort);
}

Runner::~Runner()
{
    for (sorters_t::iterator it = sorters.begin(); it != sorters.end(); ++it) {
        delete *it;
    }
}

void Runner::Run(int (*cmp)(const void *, const void *),
                 void** (*make_array)(),
                 void (*free_array)(void **))
{    
    for (sorters_t::iterator it = sorters.begin(); it != sorters.end(); ++it) {
        void** arrPtr = (void **) make_array();
        (*it)->sort(arrPtr, NUM_ELEMS, cmp);
        
        bool sorted = true;
        for (int i=0, j=1; j<NUM_ELEMS; ++i, ++j) {
            if (cmp(arrPtr[i], arrPtr[j]) > 0)
            {
                sorted = false;
            }
        }
        
        if (sorted)
        {
            cout << "OK \t\t" + (*it)->getName() << endl;
        }
        else 
        {
            cout << "FAILED \t" + (*it)->getName() << endl;
        }
        
        free_array(arrPtr);
    }
}
