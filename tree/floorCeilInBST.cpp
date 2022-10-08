# include "tree.h"


void FloorInBST(TreeNode *root,int k,int& ans){
    if (!root)
        return ;
    
    if (root->val<=k)
        ans = root->val;

    if (root->val>k)
        FloorInBST(root->left, k, ans);
    else
        FloorInBST(root->right, k, ans);
}


void CeilInBST(TreeNode *root,int k){
    int ceil=-1;
    while (root!=NULL) {
        if (root->val>=k)
            ceil=root->val;
        
        if (root->val>k)
            root = root->left;
        else
            root = root->right;
    }
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