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