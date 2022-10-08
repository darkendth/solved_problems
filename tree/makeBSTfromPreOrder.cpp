# include "tree.h"
#include <asm-generic/errno.h>
#include <vector>

using iter = vector<int>::const_iterator;


TreeNode *makeBST(iter pbeg,iter pend,iter ibeg,iter iend,map<int,iter>& hmap){
    if (pbeg>=pend||ibeg>=iend)
        return NULL;
    
    TreeNode *root = new TreeNode;
    root->val = *pbeg;
    iter m=hmap[*pbeg];
    int n=m-ibeg;
    root->left = makeBST(pbeg+1, pend+n, ibeg, m-1, hmap);
    root->right = makeBST(pbeg+n+1, pend, m+1, iend, hmap);
    return root;
}


void answer(){
    vector<int> pre;
    int n,temp;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>temp;
        pre.push_back(temp);
    }    
    vector<int> inodr(pre);
    map<int,iter> mp;
    for (int i=0;i<inodr.size();i++){
        mp[inodr[i]]=inodr.begin()+i;
    }
    iter pbeg=pre.begin(),pend=pre.end();
    iter ibeg=inodr.begin(),iend=inodr.end();

    TreeNode *root = makeBST(pbeg,pend,ibeg,iend,mp);
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