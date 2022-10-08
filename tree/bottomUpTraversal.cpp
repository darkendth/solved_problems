# include "tree.h"
#include <queue>
#include <vector>


vector<vector<int>> bottomUp(TreeNode *root){
    queue<TreeNode *> q;
    if (root)
        q.push(root);
    vector<vector<int>> res;
    TreeNode *cur;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for (int i=0;i<q.size();i++){
            cur = q.front();
            q.pop();
            temp.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        res.push_back(temp);
    }
    reverse(res.begin(),res.end());
    return res;
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    cout<<endl;
    
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