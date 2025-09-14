#include <iostream>
#include "search.hpp"

using namespace std;

Graph graph1();
Graph graph2();
Graph graph3();

int main() {
 
  Graph g1(graph1());
  Graph g2(graph2());
  
  for(int i=0; i<6; i++){
    cout << "index = " << g1[i].index << " ";
    cout << "degree = " << g1[i].degree << " ";
    cout << endl << endl;  
  }

  // Node* n = &graph[1];
  // for(int j = 0; j < n->degree; j++){
  //   cout << n->next[j] << " ";
  // }
  cout << endl;
  // DFS(graph, 0, visited, st);t
  cout << endl <<"graph 1" << endl;
  traverse(g1);
  cout << endl << "graph 2" << endl;
  traverse(g2);
}

Graph graph1(){
  Graph graph(6);
  int a0[] = {1,3};
  int a1[] = {0, 2, 4};
  int a2[] = {1, 3};
  int a3[] = {0, 2};
  int a4[] = {1, 5};
  int a5[] = {4};

  add_vertices(&graph[0], a0, 2);
  add_vertices(&graph[1], a1, 3);
  add_vertices(&graph[2], a2, 2);
  add_vertices(&graph[3], a3, 2);
  add_vertices(&graph[4], a4, 2);
  add_vertices(&graph[5], a5, 1);
  
  return graph;
}

Graph graph2(){
  Graph graph(7);
  int a0[] = {1};
  int a1[] = {0,2,3};
  int a2[] = {1,3};
  int a3[] = {1,2};
  int a4[] = {5,6};
  int a5[] = {4,6};
  int a6[] = {4,5};

  add_vertices(&graph[0], a0, 1);
  add_vertices(&graph[1], a1, 3);
  add_vertices(&graph[2], a2, 2);
  add_vertices(&graph[3], a3, 2);
  add_vertices(&graph[4], a4, 2);
  add_vertices(&graph[5], a5, 2);
  add_vertices(&graph[6], a6, 2);

  return graph;
}