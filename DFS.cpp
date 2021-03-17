#include<bits/stdc++.h>
#include<map>
#include<cstring>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>> l;
public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T,bool> &visited){
        // Recursive function to traversed the graph
        cout<<src<<" ";
        visited[src] = true;
        //Go to all nbr of that node that is not visited
        for(T nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }

    void DFS(T src){
        map<T, bool> visited;
        // Mark all nodes as not visited in the beginning
        for(auto node_pair:l){
            T node = node_pair.first;
            visited[node] = false;
        }
        // Call helper function
        dfs_helper(src, visited);
    }
};



int main(){
    Graph<int> g;
    //g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(0,3);

    g.DFS(0); // Taking 0 as the source node
}