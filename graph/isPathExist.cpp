# include "graph.h"
#include <vector>

bool dfsTraversal(vector<vector<int>> adj,vector<int> visit,int i,int dest){
    if (i==dest)
        return true;
    visit[i]=1;
    for (auto it:adj[i]){
        if (!visit[it]){
            if (dfsTraversal(adj, visit, it, dest))
                return true;
        }
    }
    return false;
}

bool validPath(vector<vector<int>> adj,int src,int dest){
    vector<int> visit(adj.size()+1,0);
    return dfsTraversal(adj,visit,src,dest);
}

void answer(){
    int n,u,v;
    cin>>n;
    vector<vector<int>> adj(n);
    /* Directed Graph. */
    for (int i=0;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>u>>v;
    displayGraph(adj);
    if (validPath(adj, u, v))
        cout<<"True";
    else
        cout<<"False";
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