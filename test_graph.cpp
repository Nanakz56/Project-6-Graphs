// *******************************************
//  test_graph_example.cpp
//  CS 271 Graph Project: Example Test File
//  Expand on these tests!
// *******************************************s

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <climits>
#include "graph.h"
using namespace std;

string exampleShortestPath = "0->2->3";
string example2ShortestPath = "0->5->9";
string exampleCharFloat = "f->g->d->j";

void test_DFS(string textfile)
{
   Graph<int, string> g;
   g.createGraphFromFile(textfile);
   auto start = chrono::high_resolution_clock::now();
   g.DFS();
   auto end = chrono::high_resolution_clock::now();
   chrono::duration<double> elapsed = end - start;
   cout << "DFS took " << elapsed.count() << " seconds." << endl;
}

void test_topologicalSort(string textfile)
{
   // create graph from file example.txt
   Graph<int, string> g;
   g.createGraphFromFile(textfile);
   string topSortResult = g.topologicalSort();
   cout << "Topological Sort Result: " << topSortResult << endl;
   if (topSortResult != "0->1->2->3") {
       cout << "Topological sort result is incorrect. Expected: 0->1->2->3 but got: " << topSortResult << endl;
   }
}


void printHeader(string filename){
    cout << "========================================="<<endl;
    cout << "Testing operations for " << filename <<endl;
    cout << "========================================="<<endl;
}

template<class K, class D>
void insertDiffEdges(Graph<K, D>& g){
    //weights remain the same. bi-directional traversal for the following vertices
    g.insertEdge(5, 0, 2);
    g.insertEdge(6, 2, 3);
    g.insertEdge(4, 1, 7);
    g.insertEdge(9,5,6);
    g.insertEdge(8, 3, 1);
}

int main()
{
    //Case 1: Directed, Weight Graph (simple)
    Graph<int, string> g;
    g.createGraphFromFile("example.txt");
    printHeader("example.txt");
    cout << "Graph created from file:" << endl;
    cout << g.toString() << endl;
    
    test_DFS("example.txt");
    test_topologicalSort("example.txt");
    g.test_BFS(0);
    g.test_shortestPath(0, 3, exampleShortestPath);
    g.test_asAdjMatrix();
    
    //Case 2: Directed, Weighted Graph (more range of values + integer vertices)
    g.createGraphFromFile("example2.txt");
    printHeader("example2.txt");
    cout << "Graph created from file:" << endl;
    cout << g.toString() << endl;    
    g.test_BFS(0);
    g.test_shortestPath(0,9, example2ShortestPath);
    g.test_asAdjMatrix();

    //Case 2a: Creating an undirected from a directed graph (not fully)
    insertDiffEdges(g);

    //Case 3: Creating graphs of vertices with varying data types
    Graph<char, float> c;
    c.createGraphFromFile("example_Char_Float.txt");
    printHeader("example_Char_Float.txt");
    cout << "Graph created from file:" << endl;
    cout << c.toString() << endl;
    c.test_BFS('e');
    c.test_asAdjMatrix();

    Graph<string, bool> d;
    d.createGraphFromFile("example_String_Bool.txt");
    printHeader("example_String_Bool.txt");
    cout << "Graph created from file:" << endl;
    cout << d.toString() << endl;
    d.test_BFS("gamma");
    d.test_asAdjMatrix();
   
    cout << "Testing completed" << endl;

    return 0;
}
