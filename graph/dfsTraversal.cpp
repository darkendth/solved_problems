# include "graph.h" 



void dfs(int u,vector<int>& visit,vector<int> adj[],vector<int>& dfs_path){
    dfs_path.push_back(u);
    visit[u]=1;
    for (auto it:adj[u]){
        if (!visit[it])
            dfs(it,visit,adj,dfs_path);
    }
}

vector<int> dfs_traversal(vector<int> adj[], int v){
    vector<int> dfs_path;
    vector<int> visit(v+1,0);
    for (int i=1;i<v;i++){
        if (!visit[i])
            dfs(i,visit,adj,dfs_path);
    }
    return dfs_path;
}


void answer(){
    vector<int> adj[6];
    make_graph(adj);
    print_graph(adj);
    vector<int> res;
    res = dfs_traversal(adj, 6);
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