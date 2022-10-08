#include "tree.h"


TreeNode *makeTree(vector<int>& pre,int pb,int pe,vector<int>& ino,int ib,int ie){

    /*
        O(n^2) Approach .
        Linear Search every time to find in Inorder.
    */

    if (pb>pe)
        return NULL;

    TreeNode *temp=new TreeNode;
    temp->val=pre[pb];
    int findat=0,n=0;
    for (int i=ib;i<=ie;i++){
        if (temp->val==ino[i]){
            findat=i;
            break;
        }
        n++;
    }
    temp->left = makeTree(pre,pb+1,pb+n,ino,ib,findat-1);
    temp->right = makeTree(pre, pb+n+1, pe ,ino, findat+1,ie );
    return temp;
}

TreeNode *makeTreeB(vector<int>& pre,int pb,int pe,vector<int>& ino,int ib,int ie,map<int,int>& hmap){

    /*
        TC = O(n),SC = O(n) .
        Use Hash map to store index of elements so that search time can be O(1).
    */

    if (pb>pe||ib>ie)
        return NULL;

    TreeNode *temp=new TreeNode;
    temp->val=pre[pb];
    int findat=hmap[pre[pb]];
    int n=findat-ib;

    temp->left = makeTreeB(pre,pb+1,pb+n,ino,ib,findat-1,hmap);
    temp->right = makeTreeB(pre, pb+n+1, pe ,ino, findat+1,ie,hmap );
    return temp;
}



void answer(){
    int n,t;
    cin>>n;
    vector<int> in;
    vector<int> pre;
    map<int,int> hmap;
    for(int i=0;i<n;i++){
        cin>>t;
        pre.push_back(t);
    }

    for(int i=0;i<n;i++){
        cin>>t;
        in.push_back(t);
        hmap[t]=i;
    }
    // TreeNode *root=makeTree(pre,0,pre.size()-1,in,0,in.size()-1);
    TreeNode *root=makeTreeB(pre,0,pre.size()-1,in,0,in.size()-1,hmap);

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