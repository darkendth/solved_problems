# include <iostream>
# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

int s;

TreeNode* buildTree(){
    /* create tree using level order traversal */
    int val;
    
    cin>>val;
    s--;
    if (val == 0 || s<0)
        return NULL;
    TreeNode *temp = new TreeNode;
    temp->val = val;
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

void preOrder(TreeNode *root){
    if (root){
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}