#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int>* l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addedge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(int neigh : l[i]){
                cout<< neigh <<",";
            }
            cout<<endl;
            
        }
    }
    void bfs(){
        queue<int> q;
        vector<bool> vis(V,false);
        q.push(0);
        vis[0] = true;
        while(q.size() > 0){
            int u = q.front();
            q.pop(); // src
            cout<<u<<" ";
            for(int v : l[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }

            }

        }


    } 
    // dfs traversal 
    void dfshelper(int u , vector<bool>& vis){
        cout<<u<<" ";
        vis[u] = true;
        for(int v : l[u]){
            if(!vis[v]){
                dfshelper(v , vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(v, false);
        for(int i =0; i<V; i++){
            if(!vis[v]){
                dfshelper(v, vis);
            }
        }
    }
    bool isundirectdfs(int src , int par , vector<bool> &vis){ // time complexity O(v+E)
        vis[src] = true;
        list<int> neighbour = l[src];
        for(int v: neighbour){
            if(!vis[v]){
                if(isundirectdfs(v , src , vis)){
                    return true;
                }
            }
             else if (v != par){
                return true;
            }
        }
        return false;
    }

    bool iscycle(){
        vector<bool> vis(V, false);
        for(int i =0; i<V; i++){
            if(!vis[i]){
                if(isundirectdfs(i, -1 , vis)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main() {
    Graph g(5);

    // Component 1
    g.addedge(0, 1);
    g.addedge(1, 2);

    // Component 2
    g.addedge(3, 4);

    cout<< g.iscycle()<< endl;

    return 0;
}