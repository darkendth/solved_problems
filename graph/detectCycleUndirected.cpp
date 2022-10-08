# include "graph.h"
#include <vector>



bool isCycleBFS(int node,vector<int> adj[],vector<int> visited){
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node]=1;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        cout<<p.first<<endl;
        for (auto it:adj[p.first]){
            if (visited[it]&&it==p.second)
                return true;
            else{
                if (!visited[it]){
                    q.push({it,node});
                    visited[it]=1;
                }
                    
            }
        }
    }
    return false;
}


bool isCycleDFS(int node,int parent,vector<int> adj[],vector<int>& visited){
    visited[node] = 1;
    for (auto it:adj[node]){
        if (!visited[it])
            return isCycleDFS(it, node, adj, visited);
        else if (parent != it)
            return true;
    }
    return false;
}

void detectCycleUsingDFS(vector<int> adj[],int n){
    vector<int> visited(n+1,0);
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            if (isCycleDFS(i, -1, adj, visited)){
                cout<<"true";
                return ;
            }
                
        }
    }
}



void detectCycleUsingBFS(vector<int> adj[],int n){
    vector<int> visited(n+1,0);
    for (int i=1;i<n;i++){
        if (!visited[i])
            if (isCycleBFS(i,adj,visited)){
                cout<<"true";
                return ;
            }
    }
    cout<<"false";
}


void answer(){
    vector<int> adj[6];
    make_graph(adj);
    print_graph(adj);

    detectCycleUsingDFS(adj, 5);
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