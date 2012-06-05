#ifndef algorithms_ISort_h
#define algorithms_ISort_h

using namespace std;

namespace algorithms {
    class ISort
    {
    public:
        virtual ~ISort() {}
        const virtual string getName() =0;
        virtual void sort(void **array, 
                          int n,
                          int (*cmp)(const void *, const void *)) = 0;
        virtual void sort(void **array,
                          int n) = 0;
    };
}

#endif
