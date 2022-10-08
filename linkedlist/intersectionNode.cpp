# include "list.h"
#include <cstddef>


ListNode* findIntersection(ListNode *headA,ListNode *headB){
    ListNode *l1=headA;
    ListNode *l2=headB;

    while (l1!=l2){
        if (l1==NULL)
            l1 = headB;
        else if (l2==NULL)
            l2 = headA;
        else {
            l1 = l1->next;
            l2 = l2->next;
        }
        
    }
    return l1;
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