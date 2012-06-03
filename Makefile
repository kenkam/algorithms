main: sorting
	clang++ -Wall -I./include -o algorithms src/main.cpp *.o
	rm *.o
	
sorting:
	clang++ -Wall -c -I./include src/sorting/*.cpp