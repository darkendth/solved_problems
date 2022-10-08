# include "tree.h"
#include <iostream>
#include <queue>
#include <vector>


vector<int> levelOrderTraversal(TreeNode *root){
    /*
        if we need to print nodes only. 
    */
    queue<TreeNode *> qu;
    TreeNode *current;
    if (root)
        qu.push(root);
    
    vector<int> res;
    while(!qu.empty()){
        current = qu.front();
        qu.pop();
        res.push_back(current->val);
        if (current->left)
            qu.push(current->left);
        if (current->right)
            qu.push(current->right);
    }
    return res;
}

vector<vector<int>> levelOrderTraversalWithLevelWise(TreeNode *root){
    queue<TreeNode *> qu;
    TreeNode *current;
    if (root)
        qu.push(root);
    
    vector<vector<int>> res;
    while (!qu.empty()){
        vector<int> level;
        int n=qu.size();
        for (int i=0;i<n;i++){
            current = qu.front();
            qu.pop();
            level.push_back(current->val);
            if (current->left)
                qu.push(current->left);
            if (current->right)
                qu.push(current->right);
        }
        res.push_back(level);
    }
    return res;
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    vector<int> res;
    res = levelOrderTraversal(root);

    cout<<"\n";
    for(auto it:res)
        cout<<it<<" ";

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