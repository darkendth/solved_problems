# include "list.h"
#include <cstddef>

/* Add two numbers Represented using Linked list in reverse order. */

ListNode* AddTwoNumber(ListNode *l1,ListNode *l2){
    int carry=0;
    ListNode *start = new ListNode;
    ListNode *cur=start;
    while (l1!=NULL&&l2!=NULL){
        cur->next = l1;
        cur = cur->next;
        cur->val = (l1->val + l2->val + carry);
        carry = cur->val/10;
        cur->val = cur->val%10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1){
        cur->next = l1;
        cur = cur->next;
        cur->val = l1->val+carry;
        carry = cur->val/10;
        cur->val = cur->val%10;
        l1 = l1->next;
    }
    while (l2){
        cur->next = l2;
        cur = cur->next;
        cur->val = l2->val+carry;
        carry = cur->val/10;
        cur->val = cur->val%10;
        l2 = l2->next;
    }
    if (carry!=0){
        cur->next = new ListNode;
        cur = cur->next;
        cur->val = carry;
        cur->next = NULL;
    }
    return start->next;
}

void answer(){
    int n,m,val;
    cin>>n;
    ListNode *h1=NULL,*h2=NULL;
    for (int i=0;i<n;i++){
        cin>>val;
        insertInLL(&h1,val);
    }
    cin>>m;    
    for (int i=0;i<m;i++){
        cin>>val;
        insertInLL(&h2,val);
    }
    displayList(h1);
    displayList(h2);
    ListNode *res;
    res = AddTwoNumber(h1,h2);
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