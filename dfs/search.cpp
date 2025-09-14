#include "search.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

void traverse(Graph& g){
  // traverses dis connected graphs
  const int n = g.size();
  Stack stack(n);
  bool* visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }
  for(int j = 0; j < n; j++){
    if(!visited[j]){
      dfs(g, j, -1, visited, stack);
    }
  }
  const int csize = stack.size();
  cout << endl;
  for(int i = 0; i < csize; i++){
    cout << stack.pop() << " ";
  }
  cout << endl;
}

void dfs(Graph& g, int curr, int parent, bool* visited, Stack& stack){
  visited[curr] = true;
  stack.push_back(curr);
  Node* node = &g[curr];
  const int degree = node->degree;
  int* vertices = node->next;
  for(int i = 0; i < degree; i++){
    int vertex = vertices[i];
    if(!visited[vertex]){
      // stack.push_back(curr);
      dfs(g, vertex, curr, visited, stack);
    }else{
      Stack st(stack);
      // int parent = st.top();
      if(!st.is_empty() && parent != vertex && st.size() > 1){
        // cycle
        cout << "\ncycle detected\n";
        cout << vertex << " ";
        const int stsize = st.size();
        int item = -1;
        for(int j = 0; j < stsize && item != vertex; j++){
          item = st.pop();
          cout << item << " ";
        }
        //
      }
    }
  }
}



Stack::Stack(int n):limit(n), curr_size(0){
  arr = new int[limit];
}

Stack::Stack(const Stack& st):limit(st.limit), curr_size(st.curr_size){
  arr = new int[limit];
  for(int i = 0; i < curr_size; i++){
    arr[i] = st.arr[i];
  }
}

Stack::~Stack(){
  delete [] arr;
}

int Stack::top() const{
  if(curr_size > 0){
    return arr[curr_size-1];
  }else{
    throw out_of_range("empty stack <top>");
  }
}

int Stack::pop(){
  if(curr_size > 0){
    curr_size--;
    return arr[curr_size];
  }else{
    throw out_of_range("empty stack <pop>");
  }
}

void Stack::push_back(int item){
  if(curr_size <= limit){
    arr[curr_size] = item;
    curr_size++;
  }else{
    throw out_of_range("stack is full");
  }
}

Graph::Graph(const int n):vsize(n){
  nodes = new Node[this->vsize];
  for(int i = 0; i < n; i++){
    nodes[i].index = i;
  }
}

Graph::~Graph(){
  for(int i = 0; i < this->vsize; i++){
    Node node = nodes[i];
    if(node.next != nullptr){
      delete [] node.next;
    }
  }
  delete [] nodes;
}

Node& Graph::operator[](int index){
  return nodes[index];
}

Node* Graph::operator->(){
  return nodes;
}

Node* add_vertices(Node* node, int arr[], int nsize){
  node->next = new int[nsize];
  for(int i = 0; i < nsize; i++){
    node->next[i] = arr[i];
  }
  node->degree = nsize;
  return node;
}