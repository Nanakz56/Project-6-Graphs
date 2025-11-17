# test: Dr. Currin's method testing
test: test_graph_example.o
	g++ -std=c++17 -o test test_graph_example.o

test_bst_example.o: test_graph_example.cpp graph.h graph.cpp
	g++ -std=c++17 -c test_graph_example.cpp

clean:
	rm -f *.o test

