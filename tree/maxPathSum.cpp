# include "tree.h"
#include <climits>

int  maximumPathSum(TreeNode *root,int& maxi){
    if (!root)
        return 0;
    int left = maximumPathSum(root->left, maxi);
    int right = maximumPathSum(root->right, maxi);
    if ((root->val+left+right)>maxi)
        maxi = root->val+left+right;
    
    return root->val+max(left,right);
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    int path,maxi=INT_MIN;
    path = maximumPathSum(root,maxi);
    cout<<maxi;

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