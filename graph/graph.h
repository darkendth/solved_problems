# include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void make_graph(vector<int> adj[]);
void make_graph_w(vector<pair<int,int>> adj[]);
void print_graph(vector<int> adj[]);
void print_graph_w(vector<pair<int,int>> adj[]);

void make_graph(vector<int> adj[]){
    int n,u,v;
    cin>>n;
    adj = new vector<int>(n);
    int t;
    cin>>t;
    for (int i=0;i<n;i++){
        cin>>u;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void make_graph_w(vector<pair<int,int>> adj[]){
    int n,u,v,w;
    cin>>n;
    adj = new vector<pair<int,int>>(n);
    int t;
    cin>>t;
    for (int i=0;i<n;i++){
        cin>>u;
        cin>>v;
        cin>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}

void print_graph(vector<int> adj[]){
    for (int i=1;i<6;i++){
        cout<<i<<" -> ";
        for (int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_graph_w(vector<pair<int,int>> adj[]){
    for (int i=1;i<6;i++){
        cout<<i<<" -> ";
        for (int j=0;j<adj[i].size();j++){
            cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<"),";
        }
        cout<<endl;
    }
    cout<<endl;
}

void displayGraph(vector<vector<int>> adj){
    for (int i=0;i<adj.size();i++){
        cout<<i<<" -> ";
        for (int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
}