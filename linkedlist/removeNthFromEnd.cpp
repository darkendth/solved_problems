# include "list.h"
#include <cstddef>


ListNode* deleteNthFromEnd(ListNode *head,int n){
    /* One pass solution */

    ListNode *list=new ListNode;
    list->next = head;
    ListNode *slow=list,*fast=list;
    for (int i=1;i<=n;i++)
        fast = fast->next;
    
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
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