# include "tree.h"
#include <cstddef>
#include <queue>
#include <sstream>
#include <string>


string serialize(TreeNode *root){
    queue<TreeNode *> q;
    TreeNode *cur;
    string s="";
    if (root)
        q.push(root);
    while(!q.empty()){
        cur = q.front();
        q.pop();

        if (cur==NULL)
            s.append("#,");
        else
            s.append(to_string(cur->val)+",");
        
        if (cur!=NULL){
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data){
    if (data.empty())
        return NULL;
    stringstream s(data);
    string str;
    TreeNode *root=new TreeNode;
    TreeNode *cur;
    getline(s,str,',');
    root->val = stoi(str);
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        getline(s,str,',');
        if (str=="#")
            cur->left=NULL;
        else{
            TreeNode *temp = new TreeNode;
            cur->left = temp;
            temp->val = stoi(str);
            q.push(temp);
        }
        getline(s,str,',');
        if (str=="#")
            cur->right=NULL;
        else{
            TreeNode *temp = new TreeNode;
            cur->right=temp;
            temp->val = stoi(str);
            q.push(temp);
        }
    }
    return root;
}



void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<endl;
    string encoded = serialize(root);
    TreeNode *res = deserialize(encoded);
    preOrder(res);
    
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