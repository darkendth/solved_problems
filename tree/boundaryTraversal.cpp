# include "tree.h"
#include <cstddef>
#include <vector>

/*
    TestCase :
    23
    1 2 3 0 4 5 0 0 6 0 0 0 7 0 8 0 9 10 0 0 11 0 0
*/

void leftBoundary(TreeNode *root,vector<int>& left){
    // vector<int> left;
    TreeNode *current=root;
    while(current!=NULL){
        if ((current->left)||(current->right))
            left.push_back(current->val);
        
        if (current->left)
            current = current->left;
        else
            current = current->right;
    }
    
}

void leafNodes(TreeNode *root,vector<int>& leaf){
    if (root){
        leafNodes(root->left, leaf);
        if ((!root->left)&&(!root->right))
            leaf.push_back(root->val);
        leafNodes(root->right, leaf);
    }
}

void rightBoundary(TreeNode *root,vector<int>& right){
    vector<int> r;
    TreeNode *current = root;
    while (current != NULL){
        if ((current->left)||(current->right))
            r.push_back(current->val);
        
        if (current->right)
            current = current->right;
        else
            current = current->left;
    }

    reverse(r.begin(),r.end());
    right.insert(right.end(),r.begin(),r.end());
}

vector<int> boundaryTraversal(TreeNode *root){
    vector<int> bt;
    if (!root)
        return {};

    bt.push_back(root->val);
    leftBoundary(root->left,bt);
    leafNodes(root,bt);
    rightBoundary(root->right,bt);

    return bt;
}

void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    vector<int> res;
    res = boundaryTraversal(root);
    cout<<"\nBoundary Traversal ";
    for (int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<"\n";
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