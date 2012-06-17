main: sorting
	clang++ -Wall -I./include -o algorithms src/main.cpp src/Runner.cpp *.o
	rm *.o
	
sorting:
	clang++ -Wall -c -I./include src/sorting/*.cpp
