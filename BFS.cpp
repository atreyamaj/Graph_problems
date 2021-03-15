#include<bits/stdc++.h>
//#include<queue>
#include<map>
#include<cstring>
using namespace std;

// Bread First Search: BFS in graphs

template <typename T>
class Graph{
    map<T, list<T>> l;
    
    public:
        void addEdge(int x, int y){// Assuming bidirectional edges
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void BFS(T src){ // Source Node
            map<T, int> visited; // Store visited nodes here
            queue<T> q; // For pushing new nodes and popping old ones

            q.push(src);
            visited[src] = true;

            while(!q.empty()){// While the Queue is not empty
                T node = q.front();
                q.pop();
                cout<<node<<" ";
                for(int nbr : l[node]){ // For nbr(neighbor) that is in the adjacency list for the specific node
                    if(!visited[nbr]){
                        q.push(nbr); // Push unvisited neighbor into queue
                        visited[nbr] = true; // Mark the newly used neighbor as visited
                    }
                }
            }
        }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.BFS(0); // Taking 0 as the source node
}