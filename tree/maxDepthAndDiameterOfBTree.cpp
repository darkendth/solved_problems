# include "tree.h"
#include <iostream>
#include <ostream>

int maxDepth(TreeNode *root){
    if (!root)
        return 0;
    
    int depth = max(maxDepth(root->left),maxDepth(root->right));
    return depth+1;
}

int maxD=0;

void maxDiameter(TreeNode *root){
    if (!root)
        return ;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    int diameter = lh+rh;
    if (diameter>maxD)
        maxD = diameter;
    maxDiameter(root->left);
    maxDiameter(root->right);
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);    
    cout<<"\n";
    int depth = maxDepth(root);
    maxDiameter(root);
    cout<<depth<<endl;
    cout<<maxD;
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