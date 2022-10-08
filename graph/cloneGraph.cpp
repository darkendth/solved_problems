# include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
    Node *clone = NULL,*temp;
    map<Node*,Node*> hmap;
    queue<Node*> q;
    if (node){
        q.push(node);
    }
    while(!q.empty()){
        Node *cur = q.front();
        q.pop();
        if (hmap.find(cur)==hmap.end()){
            temp = new Node(cur->val);
            if (clone == NULL)
                clone = temp;
            for (int i=0;i<cur->neighbors.size();i++){
                if (hmap.find(cur->neighbors[i])==hmap.end()){
                        Node *p = new Node(cur->neighbors[i]->val);
                        hmap[cur->neighbors[i]]=p;
                        temp->neighbors.push_back(p);
                        q.push(cur->neighbors[i]);
                }
                else{
                    temp->neighbors.push_back(hmap[cur->neighbors[i]]);
                }
                
            }
            hmap[cur]=temp;
            
        }
        else{
            temp = hmap[cur];
            for (int i=0;i<cur->neighbors.size();i++){
                if (hmap.find(cur->neighbors[i])==hmap.end()){
                    Node *p = new Node(cur->neighbors[i]->val);
                    hmap[cur->neighbors[i]]=p;
                    temp->neighbors.push_back(p);
                    q.push(cur->neighbors[i]);
                }
                else{
                    temp->neighbors.push_back(hmap[cur->neighbors[i]]);
                }
            }
        }
        
    }
    return clone; 
    }
};


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


