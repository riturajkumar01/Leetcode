#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int> [v];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printadjlist(){
        for(int i =0; i<V; i++){
            cout<<i<<" ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";

            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.printadjlist();
}