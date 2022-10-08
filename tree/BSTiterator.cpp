# include "tree.h"
#include <cstddef>
#include <stack>

/* 
    gives next element in inorder traversel.
    time = O(n)
    space = O(h)
*/


class BSTiterator{
    stack<TreeNode *> stk;

    public:
    BSTiterator(TreeNode *root){
        pushAll(root);
    }

    TreeNode* next(){
        if (!stk.empty()){
            TreeNode *current=stk.top();
            stk.pop();
            pushAll(current->right);
            return current;
        }
        return NULL;
    }

    bool hasNext(){
        if (stk.empty())
            return false;
        else
            return true;
    }

    private:
        void pushAll(TreeNode *root){
            while (root!=NULL) {
                stk.push(root);
                root=root->left;
            }
        }
};


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