# include "tree.h"


int minDepth(TreeNode* root) {
    if (!root)
        return 0;
    
    int min1=INT_MAX,min2=INT_MAX;
    if (root->left)
        min1 = minDepth(root->left);
    if (root->right)
        min2 = minDepth(root->right);
    
    if (root->left||root->right)
        return min(min1,min2)+1;
    else
        return 1;
}

void answer(){
    
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