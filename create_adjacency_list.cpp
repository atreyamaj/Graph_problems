#include<bits/stdc++.h>
#include<list>
using namespace std;

class Graph{
    int V;
    // Array of lists for adjacency list construction
    list<int> *l; 

    public:
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }
        void addEdge(int x, int y){
            // Assuming Bidirectional Edge
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void printAdjList(){
            // Iterate over all vertices
            for(int i = 0; i < V; i++){
                cout<<"Vertex: "<<i<<" -->";
                for(int nbr:l[i]){ // Loop Meaning: For every neighbor in l[i]
                    cout<<nbr<<"  ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    cout<<"Hello"<<endl;
    g.printAdjList();

    return 0;
}