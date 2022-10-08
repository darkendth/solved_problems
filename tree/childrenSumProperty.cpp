# include "tree.h"


void childrenSum(TreeNode *root){
    if (!root)
        return ;
    
    int total=0;
    if (root->left)
        total += root->left->val;
    if (root->right)
        total += root->right->val;
    if (total<root->val){
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }
    childrenSum(root->left);
    childrenSum(root->right);

    int maxval=0;
    if (root->left)
        maxval += root->left->val;
    if (root->right)
        maxval += root->right->val;
    if (root->left||root->right)
        root->val = maxval;
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<endl;
    childrenSum(root);
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