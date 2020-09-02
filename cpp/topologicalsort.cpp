
#include <iostream>
#include <stack>

using namespace std;

class Graph {
    public:
        Graph();
        void addEdge(int v, int w);
        void topologicalSort();
        void topologicalSortUtil(int, bool[], stack<int>&);
    protected:
        int V;
        list<int> *adj;
        list<int> *visited;

};

Graph::Graph(int V) {

    this->V = V;
    adj = new list<int>[V];
    visited = new list<int>[V];
}

Graph::addEdge(int v, int w) {

    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& s) {

    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            topologicalSortUtil(i, visited, s);

    s.push(v);
}

void Graph::topologicalSort() {

    stack<int> reverseOrder;
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            topologicalSortUtil(i, visited, reverseOrder);

    while(!reverseOrder.empty()) {
        cout << reverseOrder.top() <<" ";
        reverseOrder.pop();
    }
}
