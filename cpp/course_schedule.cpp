
#include <iostream>
#include <list>


using namespace std;


class Graph {

    public:
        Graph(int v);
        void addEdge(int v, int w);
        bool isCycle();
        bool isCycleUtil(int, bool**, bool**);

    private:
        int V;
        list<int> *adj;
};

Graph::Graph(int v) {
    
    V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {

    adj[v].push_back(w);
}

bool Graph::isCycleUtil(int v, bool **visited, bool **recStack) {

    if((*visited)[v] == false) {
        
        (*visited)[v] = true;
        (*recStack)[v] = true;

        list<int>::iterator itr;
        for(itr = adj[v].begin(); itr != adj[v].end(); itr++) {
            if(!(*visited)[v] && isCycleUtil(*itr, visited, recStack))
                return true;
            else if(recStack[*itr])
                return true;
        }
    }
    (*recStack)[v] = false;
    return false;
}

bool Graph::isCycle() {

    bool* visited = new bool[V];
    bool* recStack = new bool[V];

    for(int i=0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i=0; i < V; i++){
        cout << "Calling isCycleUtil with " << i << endl;
        if(isCycleUtil(i, &visited, &recStack))
            return true;
    }

    return false;
}


int main() {

    int num_of_courses = 2;
    Graph* g = new Graph(num_of_courses);
    g->addEdge(1, 0);
    g->addEdge(0, 1);

    if(g->isCycle()) {
        cout << num_of_courses << " can't be finished due to conflicting prerequisites." << endl;
    } else {
        cout << num_of_courses << " can be finished." << endl;
    }

    return 0;
}
