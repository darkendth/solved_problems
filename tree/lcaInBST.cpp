# include "tree.h"

TreeNode *LCAinBST(TreeNode *root,TreeNode *p,TreeNode *q){
    if (!root)
        return NULL;
    
    if ((root->val>p->val && root->val<q->val)||(root->val>q->val&&root->val<p->val))
        return root;

    if (p->val<root->val)
        LCAinBST(root->left, p, q);
    else
        LCAinBST(root->right, p, q);
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