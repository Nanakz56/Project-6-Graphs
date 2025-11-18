# test: Dr. Currin's method testing
test: test_graph.o
	g++ -std=c++17 -o test test_graph.o

test_graph.o: test_graph.cpp graph.h graph.cpp
	g++ -std=c++17 -c test_graph.cpp

clean:
	rm -f *.o test

