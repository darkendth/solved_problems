# include "tree.h"
# include "bst.h"
#include <cstddef>

bool twoSum(TreeNode *root,int k){
    BSTiteratorIn left(root);
    BSTiteratorRIn right(root);
    TreeNode *l,*r;
    if (left.hasNext())
        l=left.next();
    if (right.hasBefore())
        r=right.before();
    while(l!=NULL&&r!=NULL&&l->val<=r->val){
        int sum=l->val+r->val;
        if (sum==k)
            return true;
        if (sum<k)
            l = left.next();
        else
            r = right.before();
    }
    return false;
}


void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<"\n";
    int k=9;
    bool res=twoSum(root, k);
    cout<<res<<endl;
    
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