#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class solution{
    public:
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return 1+ max(maxDepth(root->left) , maxDepth(root->right));
    }
};

int main(){
    solution sol;
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Maximum depth: " << sol.maxDepth(root) << endl;
    
    return 0;
}












#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool isVowels(char ch){
    ch = tolower(ch);
    ch= toupper(ch);
     return ch =='a'|| ch =='e'|| ch =='i'||
     ch =='o'|| ch =='u'|| ch =='A'|| ch =='E'|| ch =='I'||ch =='O'|| ch =='U';
}
string remVowel(const string& str){
    string res = str;
    res.erase(remove_if(res.begin(), res.end(), isVowels),res.end());
    return res;
}
int main(){
    cout<<"enter a string : ";
    string str;
    getline(cin,str); // read full line including space also
    cout<<"string without vowels : "<<remVowel(str)<<endl;
    return 0;
}