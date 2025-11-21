#Dr. Currin's test file
test: test_graph_example.o
	g++ -std=c++17 -o test test_graph_example.o

test_graph_example.o: test_graph_example.cpp graph.h graph.cpp
	g++ -std=c++17 -c test_graph_example.cpp

#Group's extended test file
test1: test_graph.o
	g++ -std=c++17 -o test1 test_graph.o

test_graph.o: test_graph.cpp graph.h graph.cpp
	g++ -std=c++17 -c test_graph.cpp

clean:
	rm -f *.o test
