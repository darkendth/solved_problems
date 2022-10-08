# include "list.h"
#include <cstddef>

ListNode *rotateRight(ListNode *head,int k){
    int len = lengthOfLL(head);
    k = k%len;
    ListNode *temp = new ListNode;
    temp->next = head;
    ListNode *slow=temp,*fast=temp;
    for (int i=1;i<=k;i++){
        fast = fast->next;
    }
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = NULL;
    return head;
}


void answer(){
    int n,val;
    cin>>n;
    ListNode *head=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&head,val);
    }
    int k;
    cin>>k;
    ListNode *res;
    res = rotateRight(head,k);
    displayList(res);
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