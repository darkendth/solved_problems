# include "tree.h"
#include <cstddef>


TreeNode* kthLargest(TreeNode *root,int& k){
    if (root==NULL)
        return NULL;

    TreeNode *right = kthLargest(root->right, k);
    if (right)
        return right;
    
    k--;

    if (k==0)
        return root;
    
    return kthLargest(root->left,k);    
    
}   

TreeNode *kthSmallest(TreeNode *root,int& k){
    if (!root)
        return nullptr;
    
    TreeNode *left = kthSmallest(root->left, k);
    if (left)
        return left;
    
    k--;
    if (k==0)
        return root;
    
    return kthSmallest(root->right, k);
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