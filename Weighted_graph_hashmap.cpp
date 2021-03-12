#include<bits/stdc++.h>
#include<unordered_map>
#include<cstring>
#include<list>
using namespace std;

// If Graph has nodes that are not number values (eg: "A", "B", "C"), must use a hashmap.
// Also, each edge is weighteed. For ex: Going from A to B takes 20 units, A to D, 30 units, B to D 40 units, etc.

// So our Map starts looking like this:
// A--> (B,20), (D,30)
//B --> (D,40)
// etc. 

class Graph{
    // Adj List
    unordered_map<string, list<pair<string,int > > >  l;
    public:
        void addEdge(string x, string y, bool bidir, int wt){ // Bidir signifies if bidirectional or not, wt = weight of the edge
            l[x].push_back(make_pair(y, wt));
            if (bidir){
                l[y].push_back(make_pair(x, wt));
            }
        }
        void printAdjList(){
            // Iterate over all keys in map
            for(auto p : l){ // For every key+list pair in the map
                string city = p.first; // Node
                list<pair<string, int>> neighbors = p.second; //Edges
                
                cout<<city<<"-> ";
                for(auto nbr : neighbors){
                    string dest = nbr.first; //dest = destination city/node
                    int dist = nbr.second;

                    cout<<dest<<" "<<dist<<", ";
                }

                cout<<endl;
            }
        }
};

int main(){
    Graph g;
    g.addEdge("A", "B", true, 20); // Boolean: Bidirectional eedge or not, 20 = weight/cost of edge
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    cout<<"Hello"<<endl;
    g.printAdjList();

    return 0;
}