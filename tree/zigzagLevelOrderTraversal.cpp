# include "tree.h"
#include <iterator>
#include <queue>
#include <tuple>
#include <vector>



vector<vector<int>> zigZag(TreeNode *root){
    queue<TreeNode *> q;
    TreeNode *current;
    if (root)
        q.push(root);
    
    vector<vector<int>> res;
    bool flag=true; // true for left to right else false.
    while(!q.empty()){
        vector<int> level;
        int n = q.size();
        for (int i=0;i<n;i++){
            current = q.front();
            q.pop();
            level.push_back(current->val);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push((current->right));
        }
        if (!flag){
            reverse(level.begin(),level.end());
            flag = true;
        }
        else 
            flag = false;
        
        res.push_back(level);
    }
    return res;
}

void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    
    cout<<"\nZigZag : ";
    vector<vector<int>> res = zigZag(root);

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