# include "tree.h"
#include <climits>

struct Cart{
    int sum;
    int smallest;
    int largest;
};
typedef struct Cart Cart;

int max_sum;

Cart maxSumBST(TreeNode *root){
    if (!root){
        Cart c;
        c.sum=0;
        c.smallest=INT_MAX;
        c.largest=INT_MIN;
        return c;
    }
    if (!(root->left)&&!(root->right)){
        Cart c;
        c.sum=root->val;
        c.smallest=root->val;
        c.largest=root->val;
        return c;
    }
    Cart left = maxSumBST(root->left);
    Cart right = maxSumBST(root->right);

    // Now check for valid BST.
    if (left.largest<root->val&&right.smallest>root->val){
        Cart i;
        i.sum = left.sum+root->val+right.sum;
        if (i.sum>max_sum)
            max_sum=i.sum;

        i.smallest=min(left.smallest,root->val);
        i.largest=max(right.largest,root->val);
        return i;
    }
    else {
        Cart i;
        i.sum = max(left.sum,right.sum);
        if (i.sum>max_sum)
            max_sum=i.sum;

        i.smallest = INT_MIN;
        i.largest = INT_MAX;
        return i;
    }
}



void answer(){
    TreeNode *root;
    cin>>s;
    root = buildTree();
    preOrder(root);
    cout<<endl;
    max_sum=0;
    Cart res=maxSumBST(root);
    cout<<max_sum;
    
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