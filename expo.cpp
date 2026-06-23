#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[v];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for(int i =0; i<V; i++){
            cout<<i<<"->";
            for(int v : l[i]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    bool isUndirected(int src , int par , vector<bool> &vis){
        vis[src] = true;
    }
    list<int>neigh = l[src];
    for(int v : neigh){
        if(!vis[v]){
            if(isUndirected(v , src , vis)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(){
        vector<bool>vis(v . false);
        for(int i =0; i<v; i++){
            if(!vis[i]){
                if(isUndirected(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    bool isUndirected(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neigh = l[src];
        for(int v : neigh){
            if(!vis[v]){
                if(isUndirected(v, src, vis)){
                    return true;
                }
            } else if(v != par){
                return true;
            }
        }
        return false;
    }

    bool isCycle(){
        vector<bool>vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isUndirected(i, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.printAdjList();
    g.isCycle() ? cout<<"Cycle is present" : cout<<"No cycle is present";

    return 0;
}