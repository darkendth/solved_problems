# include "tree.h"
#include <vector>


TreeNode* sortedArrayToBST(vector<int>& nums,int p,int q){
    if (p>q)
        return NULL;
    int mid = (p+q)/2;
    TreeNode *root = new TreeNode;
    root->val=nums[mid];
    root->left = sortedArrayToBST(nums, p, mid-1);
    root->right = sortedArrayToBST(nums, mid+1, q);
    return root;
}

void answer(){
    vector<int> nums;
    int n,temp;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>temp;
        nums.push_back(temp);
    }    
    TreeNode *node = sortedArrayToBST(nums,0,n-1);
    preOrder(node);
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