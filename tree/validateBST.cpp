# include "tree.h"


bool isValidate(TreeNode *root){
    /*
        this will fail for some cases, refer karumanchi
        for example q51.

    */

    if (!root)
        return true;
    if ((!root->left)&&(!root->right))
        return true;
    
    if (!isValidate(root->left)||!isValidate(root->right))
        return false;

    bool left,right;

    left = root->left?(root->left->val<root->val):true;
    right = root->right?(root->right->val>root->val):true;
    
    if (left&&right)
        return true;

    return false;
}

bool isValid(TreeNode *root,int min,int max){
    if (!root)
        return true;
    return ((root->val>min)&&(root->val<max)&&isValid(root->left, min, root->val)&&isValid(root->right, root->val, max));
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    
    bool v = isValidate(root);
    cout<<v;
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