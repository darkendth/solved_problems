# include "tree.h"
#include <queue>


void connect(TreeNode *root){
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    while(!q.empty()){
        TreeNode *current;
        int n=q.size();
        for (int i=0;i<n;i++){
            current = q.front();
            q.pop();
            if (i==n-1)
                current->next=NULL;
            else
                current->next=q.front();
            
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            
        }

    }
}

void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    connect(root);
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