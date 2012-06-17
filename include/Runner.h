#ifndef algorithms_Runner_h
#define algorithms_Runner_h

#include <vector>
#include "ISort.h"

#define NUM_ELEMS   100

namespace algorithms {
    typedef vector<ISort*> sorters_t; 
    
    class Runner
    {
    private:
        vector<ISort*> sorters;
        void printArray(void **array,
                        int n);
        
    public:
        Runner();
        ~Runner();
        void run(int (*cmp)(const void *, const void *),
                 void** (*make_array)(),
                 void (*free_array)(void **));
    };
}

#endif
