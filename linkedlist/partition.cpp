# include "list.h"
#include <cstddef>


ListNode* partition(ListNode* head, int x){
    ListNode *p = new ListNode;
    ListNode *q = new ListNode;

    ListNode *i = p;
    ListNode *j = q;
    while(head!=NULL){
        if (head->val<x){
            i->next = head;
            i = i->next;
        }
        else {
            j->next = head;
            j = j->next;
        }
        head = head->next;
    }
    i->next = q->next;
    j->next = NULL;

    return p->next;
}


void answer(){
    int n,val;
    cin>>n;
    ListNode *head=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&head,val);
    }
    int x;
    cin>>x;
    ListNode *res = partition(head,x);
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