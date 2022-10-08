// # include "tree.h"

class BSTiteratorIn{
    stack<TreeNode *> stk;

    public:
    BSTiteratorIn(TreeNode *root){
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


class BSTiteratorRIn{
    // gives element in reverse descending order (reverse inorder)
    stack<TreeNode *> stk;

    public:
    BSTiteratorRIn(TreeNode *root){
        pushAll(root);
    }

    TreeNode* before(){
        if (!stk.empty()){
            TreeNode *current=stk.top();
            stk.pop();
            pushAll(current->left);
            return current;
        }
        return NULL;
    }

    bool hasBefore(){
        if (stk.empty())
            return false;
        else
            return true;
    }

    private:
        void pushAll(TreeNode *root){
            while (root!=NULL) {
                stk.push(root);
                root=root->right;
            }
        }
};