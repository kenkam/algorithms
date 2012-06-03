#ifndef algorithms_ISort_h
#define algorithms_ISort_h

namespace algorithms {
    class ISort
    {
    public:
        virtual ~ISort() {}
        virtual void sort(void **array, 
                          int n,
                          int (*cmp)(const void *, const void *)) = 0;
    };
}

#endif
