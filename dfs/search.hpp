#ifndef SEARCH_HPP
#define SEARCH_HPP

struct Node{
  int index;
  int degree;
  int* next;

  Node():index(-1),degree(0), next(nullptr){}
};


class Stack{

public:
  Stack() = delete;
  Stack(int);
  Stack(const Stack&);
  ~Stack();

  int pop();
  int top() const;
  void push_back(int);
  int size()const{return curr_size;}
  bool is_full()const{return curr_size == limit;}
  bool is_empty()const{return curr_size == 0;}

private:
  const int limit;
  int curr_size;
  int* arr;
};

class Graph{

  friend Graph& add_neighbors(Graph& graph, int index, int arr[], int size);

public:
  Graph() = delete;
  Graph(int);
  int size(){return vsize;}
  ~Graph();

Node& operator[](int);
Node* operator->();


private:
  Node* nodes;
  const int vsize;

};

Node* add_vertices(Node* node, int arr[], int size);

void dfs(Graph& g, int index, int parent, bool* visited, Stack& stack);

void traverse(Graph& g);


#endif