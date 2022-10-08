# include "list.h"
#include <cstddef>


ListNode* flatten(ListNode *l1){
    if (l1->next==NULL)
        return l1;

    ListNode *l2 = flatten(l1->next);
    ListNode *head = merge(l1,l2);
    return head;
}


void answer(){
    
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