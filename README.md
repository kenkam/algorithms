Algorithms - A project for learning algorithms 
==============================================

Algorithms is a project for learning algorithms. It is initially implemented in C++, but may include other languages in the future. 

It is very primitive at the moment and there are things such as testing and benchmarking that would add to this project. However, there is enough code to start implementing other algorithms.

Implementation Notes
--------------------

Array of pointers was chosen in ``main.cpp`` for sorting algorithms instead of using standard library data structures to keep the algorithms themselves lightweight. Also, in the spirit of learning this served well as a reminder on how pointers worked.

Running
-------

As simple as:

    make
    ./algorithms
    