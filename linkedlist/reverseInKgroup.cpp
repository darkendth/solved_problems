# include "list.h"


ListNode* reverseKGroup(ListNode* head, int k){
    ListNode *temp = new ListNode;
    temp->next = head;
    ListNode *prev,*cur,*next;
    prev = temp;
    int len = lengthOfLL(head);

    while(len>=k){
        cur = prev->next;
        next = cur->next;
        for (int i=1;i<k;i++){
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
        }
        prev = cur;
        len -= k;
    }
    return temp->next;
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
    ListNode *res = reverseKGroup(head,k);
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