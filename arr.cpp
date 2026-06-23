/* 
 #include<iostream>
#include<string>

using namespace std;
class student{
    public:
    string name;
    int rollno;
};
class teacher {
    public:
    string subject;
    double salary;
};

class TA : public student,public teacher{// Multiple inheritance 

    public:
    };
int main(){
    TA t1;
    t1.name = " raj";
    t1.subject = "engineering";
    cout<<t1.name<<endl;
    cout<<t1.subject<<endl;
    return 0;

} 
    */

     /* 
    #include<iostream>
    using namespace std;
    class Print{
        public:
        // compile time polymorphism 
        void show(int x){
            cout<< " int : " << x << endl;
        }
        void show(char ch){
            cout<< " char "<< ch << endl;
        }
    };
    int main(){
        Print p1;
        p1.show(101);
    }
      */

 /* 

 #include<iostream>
using namespace std;
class parent {
    public:
    void getinfo(){
        cout<<" parent class \n";
    }
    virtual void hello(){
        cout<<" hello ";
    }

};
class child : public parent{
    public:
    void getinfo(){
        cout<<" child class \n ";
    }
    void hello(){
        cout<<" hello from child ";
    }
};
int main(){
    child c1;
    c1.hello();
}

 */
/*
  #include<iostream>
using namespace std;
class Shape{ // abstract class 
    public:
    virtual void draw() = 0; // pure virtual function  // also automatically called as abstract class 

};
class Circle : public Sxhape{
    public:
    void draw(){
    cout<<" Draw a circle \n ";
    }
};
int main(){
    Circle c1;
    c1.draw();
}
*/
/* 
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
    }
    // void printAdj(){
    //     for(int i =0; i<V; i++){
    //         cout << i << " -> ";
    //         for(int neigh: l[i]){
    //             cout << neigh << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    // bfs example:
void bfs(){
    vector<bool> vis(V, false);
    // disconnected graph
    for(int i =0; i<V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                cout<<u<<" ";
                for(int v : l[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
}

/* 

void bfs(){
    // diconnected graph
    vector<bool> vis(V, false);
    for(int i =0; i<V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                cout<<u<<" ";
                for(int v: l[u]){
                    if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                    }
                }
            }
        }
    }
};
// dfs keep going to 1 unvisted 
void dfshelper(int u , vector<bool> &vis){
    cout<<u<<" ";
    vis[u] = true;
    for(int v : l[u]){
        if(!vis[v]){
            dfshelper(v , vis);
        }
    }
}
void dfs(){
    int src =0;
    vector<bool> vis(V, false);
    dfshelper(src,vis);
}
};
*/
/* 
bool isUndirecteddfs(int src , int par , vector<bool> &vis){
    vis[src] = true; // current elemnt visted 
    for(int v : l[src]){
        if(!vis[v]){
            if(isUndirecteddfs(v , src , vis)){
        return true;
        }
    }
    else if(v!=par){
        return true;
    }
}
return false;
}
bool isCycle(){
    vector<bool> vis(V, false);
    for(int i =0; i<V; i++){
        if(!vis[i]){
            if(isUndirecteddfs(i, -1, vis)){
                return true;
            }
        }
    }
    return false;
}
};
int main(){

    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(6,4);
    g.printAdj();
   
   // cout << "\nDFS Traversal: ";
    //g.dfs();
    cout << "Cycle present: " << (g.isCycle() ? "Yes" : "No") << endl;
    return 0;
}
*/
/* 
void dfs(int cur , vector<bool> &vis , stack<int>& s){
    vis[cur] = true;
    for(int v : l[cur]){
        if(!vis[v]){
            dfs(v , vis , s);
        }
    }
    s.push(cur);
}
void topoSort(){
    vector<bool> vis(V, false);
    stack<int> s;
    for(int i =0; i<V; i++){
        if(!vis[i]){
            dfs(i , vis , s);
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
}; 
*/
/* 
void topologicalsort(){
    // khans algorithm 
    vector<int> indegree(V, 0);
    for(int u =0; u<V; u++){
        for(int v : l[u]){
            indegree[v]++;
        }
    }
    queue<int> q;
    for(int i =0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i); // if indegree = 0;
        }
    }

     vector<int> res;
    while(q.size() > 0){
    int u = q.front();
    q.pop();
    res.push_back(u);
    for(int v : l[u]){
        indegree[v]--;
        if(indegree[v] == 0){
            q.push(v);
           
        }
    }
}
// step 4 : Detect a Cycle 
if(res.size() !=V){
    cout<<" Detect a cycle "<<endl;
    return;
}
for(int node : res){
    cout<<node<<" ";
}
cout<<endl;
};

  int main(){
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Adjacency List:" << endl;
   // g.printAdj();

    cout << "Topological Sort: ";
    g.topologicalsort();
    return 0;
}
*/
/* 
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
    node* buildtree(node* root){
        cout<<" enter the data or -1 NULL "<<endl;
        int data;
        cin>>data;

        // base case 
        if(data == -1){
            return NULL;
        }
    root = new node(data);

    // Build left subtree
    cout << "Enter left child of " << data << endl;
    root->left = buildtree(root->left);

    // Build right subtree
    cout << "Enter right child of " << data << endl;
    root->right = buildtree(root->right);

    return root;
    }
    void inorder(node* root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        cout<< root->data<< " ";
        inorder(root->right);
    }
    void preorder(node* root){
        if(root == NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right); 
    }
    void postorder(node* root){
        if(root == NULL){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<< root->data<<" ";
    }
void levelorder(node* root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();


        if(curr == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<curr->data<<" ";
            if(curr->left)q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

    int main(){
        node* root = NULL;
        root = buildtree(root);
        

        cout<<"\n Inorder traversal "<<endl;
        inorder(root);

        cout<<"\n Preorder Traversal "<<endl;
        preorder(root);


        cout<<"\n Postorder Traversal "<<endl;
        postorder(root);
    }
        */

        /* 
#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node* insert(node* root ,int value){
    if(root == NULL){
        return new node(value);
    }
    if(value < root->data){
        root->left = insert(root->left , value);
    }
    else{
        root->right = insert(root->right , value);
    }
    return root;
}
node* buildtree(vector<int> arr){
    node* root = NULL;
    for(int value : arr){
        root = insert(root , value);
    }
    return root;
}


bool search(node* root , int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
    }
}
void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    vector<int> arr = { 5, 1,3,2,4,7};
    node* root = buildtree(arr);
    inorder(root);
    cout<<endl;
     
    cout<< search(root , 4)<<endl;
    cout<< search(root , 10)<<endl;
}
    */


    #include<iostream>
    using namespace std;
    class animal{
        public:
        void eat(){
            cout<<" Anmal is eating food Meowwww "<<endl;
        }
    };
// derived class 
    class Dog : public animal {
        public:
        void bark(){
            cout<<" dog is barking "<<endl;
        }
    };
    int main(){
        Dog d;
        d.eat();
        d.bark();

    }


