# include "tree.h"
#include <queue>
#include <utility>


int maxWidthOfBT(TreeNode *root){

    pair<TreeNode *,int> cur;
    queue<pair<TreeNode*,int>> q;
    if (root)
        q.push({root,0});
    int max_width=0;
    while(!q.empty()){
        int size=q.size();
        int leftmost=q.front().second,rightmost;
        int min=leftmost;
        for (int i=0;i<size;i++){
            if (i==size-1)
                rightmost=q.front().second;
            cur = q.front();
            q.pop();
            int x = cur.second-min;
            if (cur.first->left)
                q.push({cur.first->left,2*x+1});
            if (cur.first->right)
                q.push({cur.first->right,2*x+2});

        }
        int width = rightmost-leftmost+1;
        if (width>max_width)
            max_width=width;
    }
    return max_width;
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