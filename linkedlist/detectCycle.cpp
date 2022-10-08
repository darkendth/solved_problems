# include "list.h"
#include <cstddef>
#include <fstream>


bool hasCycle(ListNode *head){
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
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