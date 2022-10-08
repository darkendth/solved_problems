# include "list.h"
#include <cstddef>


ListNode* reverse(ListNode *head){
    ListNode *prev=NULL,*cur=head,*next=NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}


void reorder(ListNode *head){
    ListNode *slow=head,*fast=head;
    while (fast!=NULL&&fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head2=slow->next;
    slow->next = NULL;
    head2 = reverse(head2);
    displayList(head2);
    slow=head;
    while (head2!=NULL){
        fast = slow->next;
        slow->next = head2;
        head2 = head2->next;
        slow->next->next=fast;
        slow = fast;
    }
}


void answer(){
    int n,val;
    cin>>n;
    ListNode *head=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&head,val);
    }
    reorder(head);
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