# include "tree.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>

/* Morris Inorder and PreOrder Traversal */

/* input 
    11
    1 2 4 0 0 5 0 6 0 0 3
*/


void morrisInorder(TreeNode *root){
    TreeNode *cur=root;
    while (cur != NULL){
        if (cur->left == NULL){
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{
            TreeNode *pre=cur->left;
            while(pre->right!=NULL&&pre->right!=cur){
                pre = pre->right;
            }
            if (pre->right==NULL){
                pre->right=cur;
                cur = cur->left;
            }
            else {
                pre->right=NULL;
                cout<<cur->val<<" ";
                cur = cur->right;
            }
        }
    }
}

void morrisPreOrder(TreeNode *root){
    TreeNode *cur=root;
    while (cur != NULL){
        if (cur->left == NULL){
            cout<<cur->val<<" ";
            cur = cur->right;
        }
        else{
            TreeNode *pre=cur->left;
            while(pre->right!=NULL&&pre->right!=cur){
                pre = pre->right;
            }
            if (pre->right==NULL){
                cout<<cur->val<<" ";
                pre->right=cur;
                cur = cur->left;
            }
            else {
                pre->right=NULL;
                cur = cur->right;
            }
        }
    }
}





void answer(){
    TreeNode *root;
    
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    morrisInorder(root);
    cout<<endl;
    cout<<"PreOrder"<<endl;
    morrisPreOrder(root);
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