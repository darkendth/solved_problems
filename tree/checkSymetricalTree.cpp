# include "tree.h"
#include <cstddef>


bool isMirror(TreeNode *rootA,TreeNode *rootB){
    if ((rootA==NULL)&&(rootB==NULL))
        return true;
    if ((rootA==NULL)||(rootB==NULL))
            return false;
    if (rootA->val!=rootB->val)
        return false;
    if (isMirror(rootA->left, rootB->right)&&isMirror(rootA->right, rootB->left))
        return true;
    return false;
}

bool isSymmetric(TreeNode* root) {
    if (root){
        return isMirror(root->left,root->right);
    }    
    return true;
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