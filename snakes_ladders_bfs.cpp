#include<bits/stdc++.h>
//#include<queue>
#include<map>
#include<cstring>
using namespace std;

// Snakes and Ladders board game.
// Given the snakes and ladders, and their source and destination squares,
//Find:
// 1. Minimum number of Dice throws required to reach the destination/final square.
// 2. Find the shortest path as well.

// Assume no double turn on getting a 6.

// Therefore, this graph is directed/unidirectional. Also, each number/square on the board is a vertex.

// Example: from 1 we can go to 2 to 7 (all of these are edges).
// If 2 has a ladder, the ladder destination will be another edge for 2.

template <typename T>
class Graph{
    map<T, list<T>> l;
    public:
        void addEdge(int x, int y){// Assuming bidirectional edges
            l[x].push_back(y);
        }

        int BFS(T src, T dest){ 
            map<T, int> dist; // Store distance
            map<T,T> parent;
            queue<T> q; 
            
            // In the beginning, assume all other nodes to be at a distance of infinity. = INT_MAX

            for(auto node_pair : l){ // For node pair that lies in list l (Will give [integer, list])
                T node = node_pair.first; //Retrieve the integer
                dist[node] = INT_MAX;
            }

            q.push(src);
            dist[src] = 0; // In the beginning, source node will have a distance of 0
            parent[src] = src;

            while(!q.empty()){
                T node = q.front();
                q.pop();

                //cout<<node<<" ";
                
                for(int nbr : l[node]){ 
                    if(dist[nbr] == INT_MAX){// Checking if we're visiting the node for the first time
                        q.push(nbr); // If yes, then push into Q
                        dist[nbr] = dist[node] + 1; //Update distance to previous distance + 1
                        parent[nbr] = node;
                    }
                }
            }

            // Print shortest path to destination node
            //for(auto node_pair:l){
            //    T node = node_pair.first;
            //    cout<<"Node "<<node<<" dist "<<dist[node]<<endl;
            //}

            // Print source to dest path
            //Dest to source:
            T temp = dest;
            while(temp != src){
                cout<<temp<<"<--";
                temp = parent[temp];
            }
            cout<<src<<endl;

            return dist[dest];
            
        }
};

int main(){
    int board[50] = {0};

    // Jumps: Snakes means negative, ladder meands positive
    board[2] = 13; // Ladder from 2, jump of 13, so end up at 15. So, edge between 1 and 15 (1->2->15)
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = 22;

    // Add all edges to graph
    Graph<int> g;

    for(int i = 0; i < 36; i++){
        for(int dice = 1; dice <=6; dice++){
            int j = i + dice;
            j += board[j]; // Jump from j

            if(j<=36){
                g.addEdge(i,j); // Directed Edge from i to j
            }
        }
    }
    g.addEdge(36,36);

    int shortest_length = g.BFS(0, 36); //Source, Destination
    cout<<shortest_length;
}