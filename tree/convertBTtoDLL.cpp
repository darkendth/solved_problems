# include "tree.h"
#include <cstddef>

/*
    Approach is similar to flatten binary tree.
    Now left should have not equall to NULL.
*/

// struct Node{
//     int val;
//     struct Node *next;
//     struct Node *prev;
// };
// typedef struct Node Node;

TreeNode *pre=NULL;

void flattenToDLL(TreeNode *root){
    if (!root)
        return ;

    flattenToDLL(root->right);
    flattenToDLL(root->left);
    root->right=pre;
    root->left=NULL;
    if (pre)
        pre->left=root;
    pre=root;
}

void flattenToDLLB(TreeNode *root){
    /*
        use moris traversal to convert into DLL.
        TC = O(n), SC = O(1) 
    */
    TreeNode *cur=root;
    while(cur!=NULL){
        if (cur->left){
            TreeNode *p=cur->left;
            while(p->right!=NULL)
                p = p->right;
            p->right = cur->right;
            cur->right = cur->left;
        }
        cur->left = pre;
        pre = cur;
        cur = cur->right;
    }

}

void displayLinkedList(TreeNode *root){
    while(root!=NULL){
        cout<<root->val<<"->";
        root = root->right;
    }
    cout<<endl;
}

void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    cout<<endl;
    flattenToDLLB(root);
    displayLinkedList(root);

    
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