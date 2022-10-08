# include "tree.h"


int sum=0;

void sumAllNumbers(TreeNode *root,int num){
    if (!root)
        return ;
    
    num = num*10+root->val;
    if (!root->left&&!root->right){
        sum += num;
    }

    sumAllNumbers(root->left,num);
    sumAllNumbers(root->right, num);
    
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