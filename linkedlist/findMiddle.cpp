# include "list.h"
#include <cstddef>


ListNode* middleNode(ListNode *head){
    ListNode *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


void answer(){
    int n,val;
    cin>>n;
    ListNode *head=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&head,val);
    }
    displayList(head);

    cout<<endl;
    ListNode *mid = middleNode(head);
    cout<<mid->val;


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