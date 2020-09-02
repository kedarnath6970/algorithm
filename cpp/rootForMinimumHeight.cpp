
#include <iostream>
#include <list>
#include <deque>
#include <vector>

using namespace std;


class Graph {

    public:
        int V;
        list<int> *adj;
        vector<int> degree;

        Graph(int V);
        void addEdge(int v, int w);
        void printDegree();
        vector<int> rootForMinimumHeight();
};

Graph::Graph(int V) {

    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; i++)
        degree.push_back(0);
}

void Graph::addEdge(int v, int w) {

    adj[v].push_back(w);
    adj[w].push_back(v);
    degree[v]++;
    degree[w]++;
}

void Graph::printDegree() {
    
    for (int i = 0; i < V; i++)
        cout << degree[i] << " ";
    cout << endl;
}

vector<int> Graph::rootForMinimumHeight() {

    deque<int> q;

    for (int i = 0; i < V; i++)
        if (degree[i] == 1)
            q.push_back(i);

    while (V > 2) {
    
        for (int i = 0; i < q.size(); i++) {
        
            int t = q.front();
            q.pop_front();
            V--;

            for(list<int>::iterator j = adj[t].begin(); j != adj[t].end(); j++) {
    
                degree[*j]--;
                if (degree[*j] == 1) 
                    q.push_back(*j);
            }
        }
    }

    vector<int> res;
    while (!q.empty()) {
    
        res.push_back(q.front());
        q.pop_front();
    }
    return res;
}

int main() {

    Graph g(4);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    cout << "Degree of the graph nodes: " <<endl;
    g.printDegree();

    cout << "Calling rootMinimumHeight() .... " << endl;
    vector<int> res = g.rootForMinimumHeight();
    for (int i = 0; i < res.size(); i++)
        cout << res[i] <<" ";
    cout << endl;
    return 0;
}
