#include<iostream>
#include<vector
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addedge(int u , int v){
        l[u].push_back(v);
    }
    void topologicalsort(){
        vector<int> res;
        //calculate indegree
        vector<int> indeg(V , 0);
        for(int u = 0; u<V; u++){
            for(int v : l[u]){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i =0 ; i<V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        //bfs
        while(q.size() > 0){
            int u = q.front();  
            q.pop();
            res.push_back(u); // add the node to the topological order
            for(int v : l[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }

    }
}
};
int main(){
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.topologysort();
    return 0;
}