# include "tree.h"
#include <cstddef>



bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)
        return false;

    if (root->left==NULL&&root->right==NULL){
        if (targetSum-root->val==0)
            return true;
        else
            return false;
    }    

    return (hasPathSum(root->left, targetSum-root->val)||hasPathSum(root->right, targetSum-root->val));
}

vector<vector<int>> all_path;
void pathSum(TreeNode *root,int targetSum,vector<int>& path){
    /*
        all path from root to leaf node whose sum equall to target sum.
    */
    if (!root)
        return ;
    
    path.push_back(root->val);
    if (targetSum-root->val == 0&&(!root->left&&!root->right)){
        all_path.push_back(path);
    }

    pathSum(root->left, targetSum-root->val, path);
    pathSum(root->right, targetSum-root->val, path);
    path.pop_back();
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    
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