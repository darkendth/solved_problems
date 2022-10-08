# include "tree.h"
#include <cstddef>

struct node{
    int val;
    struct node *next;
};
typedef struct node Node;
Node *head;

TreeNode* sortedListToBST(Node *&list,int p,int q){
    if (p>q)
        return NULL;
    
    int mid = (p+q)/2;
    TreeNode *leftChild = sortedListToBST(list, p, mid-1);
    TreeNode *temp = new TreeNode;
    temp->val = list->val;
    temp->left = leftChild;
    list = list->next;
    temp->right = sortedListToBST(list, mid+1, q);
    return temp;
}

void insertInList(int val){
    Node *temp = new Node;
    temp->val = val;
    temp->next = NULL;
    if (head==NULL)
        head = temp;
    else{
        Node *cur=head;
        while (cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void displayList(Node *head){
    while (head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}


void answer(){
    TreeNode *root;
    int s;
    cin>>s;
    for (int i=0;i<s;i++){
        int temp;
        cin>>temp;
        insertInList(temp);
    }
    displayList(head);
    
    root = sortedListToBST(head,0,s-1);
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