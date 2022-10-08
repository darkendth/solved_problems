# include "tree.h"



void rightView(TreeNode *root,vector<int>& num,int level){
    if (!root)
        return ;
    
    if (num.size()<level){
        num.push_back(root->val);
    }
    rightView(root->right, num, level+1);
    rightView(root->left, num, level+1);
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<endl;
    vector<int> num;
    rightView(root, num, 1);
    
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