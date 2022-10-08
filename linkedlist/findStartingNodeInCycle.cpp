# include "list.h"
#include <cstddef>


ListNode* findStartOfCycle(ListNode *head){
    ListNode *slow=head,*fast=head;
    
    while(fast!=NULL&&fast->next!=NULL){
        if (fast == slow)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *temp=head;
    while(head!=slow){
        head = head->next;
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