#include<bits/stdc++.h>
//#include<queue>
#include<map>
//#include<climit>
//#include<cstring>
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

        void BFS(T src){ 
            map<T, int> dist; // Store distance
            queue<T> q; 
            
            // In the beginning, assume all other nodes to be at a distance of infinity. = INT_MAX

            for(auto node_pair : l){ // For node pair that lies in list l (Will give [integer, list])
                T node = node_pair.first; //Retrieve the integer
                dist[node] = INT_MAX;
            }

            q.push(src);
            dist[src] = 0; // In the beginning, source node will have a distance of 0

            while(!q.empty()){
                T node = q.front();
                q.pop();

                //cout<<node<<" ";
                
                for(int nbr : l[node]){ 
                    if(dist[nbr] == INT_MAX){// Checking if we're visiting the node for the first time
                        q.push(nbr); // If yes, then push into Q
                        dist[nbr] = dist[node] + 1; //Update distance to previous distance + 1
                    }
                }
            }

            // Print distance to every node.
            for(auto node_pair : l){
                T node = node_pair.first;
                int d = dist[node];
                cout<<"Node "<<node<<" distance from source node = "<<d<<endl;
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