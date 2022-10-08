# include <iostream>
#include <bits/stdc++.h>
#include <typeindex>
#include <vector>
using namespace std;

struct Node{
    int start;
    int end;
    int index;
};
typedef struct Node Node;

bool comparator(Node m1,Node m2){
    if (m1.end<m2.end)
        return true;
    else if (m1.end>m2.end)
        return false;
    else if (m1.start<m2.start)
        return true;
    else 
        return false;
}

vector<int> maxMeetingInRoom(vector<int> start,vector<int> end){
    vector<Node> meetings;
    Node meet;
    for (int i=0;i<start.size();i++){
        meet.start=start[i];
        meet.end=end[i];
        meet.index=i;
        meetings.push_back(meet);
    }
    sort(meetings.begin(),meetings.end(),comparator);
    int num=0;
    int limit=0;
    vector<int> meet_index;
    for (auto it:meetings){
        if (it.start>limit){
            num++;
            limit=it.end;
            meet_index.push_back(it.index);
        }
    }
    return meet_index;
}

void answer(){
    int n;
    cin>>n;
    vector<int> start,end;
    int t;
    for (int i=0;i<n;i++){
        cin>>t;
        start.push_back(t);
    }
    for (int i=0;i<n;i++){
        cin>>t;
        end.push_back(t);
    }
    vector<int> res=maxMeetingInRoom(start,end);
    
    for (auto it:res)
        cout<<it<<" ";
    cout<<endl;
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