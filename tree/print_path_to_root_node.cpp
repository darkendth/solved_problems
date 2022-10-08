# include "tree.h"
#include <iostream>
#include <stack>
#include <vector>


bool printPathToRoot(TreeNode *root,vector<int>& path,int k){
    if (!root)
        return false;
    
    path.push_back(root->val);
    if (root->val==k)
        return true;
    
    if (printPathToRoot(root->left, path, k)||printPathToRoot(root->right, path, k))
        return true;
    
    path.pop_back();

    return false;
}

void answer(){
    TreeNode *root;
    cin>>s;
    int k;
    cin>>k;
    root = buildTree();
    // preOrder(root);

    
    vector<int> path;
    if (printPathToRoot(root,path,k)){
        cout<<"\npath ";
        for (int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else {
        cout<<"No path\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef Redirect
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        answer();
    }

    
}