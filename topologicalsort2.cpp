#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V]; // array of lists
        
    }
    void addedge(int u , int v){
        l[u].push_back(v);
    }
    void dfs(int curr , vector<bool>& vis , stack<int>& s){
        vis[curr] = true;
        for(int v : l[curr]){
            if(!vis[v]){
                dfs(v , vis , s);
            }
        }
        s.push(curr); // push after exploring all neighbors
    }
    void topologysort(){
        vector<bool> vis(V , false);
        stack<int> s;
        for(int i= 0; i<V; i++){
            if(!vis[i]){
                dfs(i , vis , s); // call dfs for unvisited nodes
            }
        }
        while(s.size() > 0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void dfshelper(int v , vector<bool>& vis){
        cout<<u<<" ";
        vis[v] = true;
        for(int v : l[u]){ // explore neighbours
            if(!vis[v]){
                dfshelper(v , vis);
            }

        } // 
    }
    void dfs(){
        int src =0;
        vector<bool> vis (V, false);
        dfshelper(src , vis);
    }
};
int main(){
    Graph g(6);
    g.addedge(5 , 2);
    g.addedge(5 , 0);
    g.addedge(4 , 0);
    g.addedge(4 , 1);
    g.addedge(2 , 3);
    g.addedge(3 , 1);
    g.topologysort();
    return 0;
}