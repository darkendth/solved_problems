# include "tree.h"
#include <queue>
#include <vector>


vector<vector<int>> verticalOrder(TreeNode *root){
    queue<pair<TreeNode*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mp;
    int vertical=0,level=0;
    if(root)
        q.push({root,{vertical,level}});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode *current = it.first;
        vertical = it.second.first;
        level = it.second.second;
        mp[vertical][level].insert(current->val);
        if (current->left)
            q.push({current->left,{vertical-1,level+1}});
        if (current->right)
            q.push({current->right,{vertical+1,level+1}});

    }
    vector<vector<int>> ans;
    for (auto p:mp){
        vector<int> col;
        for (auto v:p.second){
            col.insert(col.end(),v.second.begin(),v.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);

    vector<vector<int>> res;

    res = verticalOrder(root);
    cout<<"\nvertical order Traversal\n";
    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

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