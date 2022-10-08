#include <cstddef>
# include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;


void insertInLL(ListNode **head,int val){
    ListNode *temp = new ListNode;
    temp->val = val;
    temp->next = NULL;
    if (*head==NULL)
        *head = temp;
    else{
        ListNode *p = *head;
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}

int lengthOfLL(ListNode *head){
    int len=0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

void displayList(ListNode *head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
