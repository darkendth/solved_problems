# include "graph.h"
#include <queue>
#include <vector>


void bfs(int node,vector<int> adj[],vector<int>& bfs_path,vector<int>& visited){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        node = q.front();
        q.pop();
        bfs_path.push_back(node);
        for (auto it:adj[node]){
            if (!visited[it]){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}


vector<int> bfs_traversal(vector<int> adj[],int n){
    vector<int> bfs_path;
    vector<int> visited(n+1,0);
    for (int i=1;i<n;i++){
        if (!visited[i])
            bfs(i,adj,bfs_path,visited);
    }
    return bfs_path;
}


void answer(){
    vector<int> adj[6];
    make_graph(adj);
    print_graph(adj);
    vector<int> res;
    res = bfs_traversal(adj,5);
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