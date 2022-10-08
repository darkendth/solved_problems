# include "list.h"
#include <cstddef>

ListNode *oddEvenList(ListNode *head){
    if (head==NULL||head->next==NULL||head->next->next==NULL)
        return head;

    ListNode *o=head;
    ListNode *e=head->next;
    head = head->next->next;
    int oddeven=1;
    ListNode *i=o,*j=e;
    while(head!=NULL){
        if (oddeven%2==0){
            e->next = head;
            e = e->next;
        }
        else{
            o->next = head;
            o = o->next;
        }
        oddeven++;
        head = head->next;
    }
    e->next = NULL;
    o->next = j;
    return i;
}

void answer(){
    int n,val;
    cin>>n;
    ListNode *head=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&head,val);
    }
    ListNode *res = oddEvenList(head);
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