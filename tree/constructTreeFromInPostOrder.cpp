# include "tree.h"


TreeNode *makeTree(vector<int>& post,int pb,int pe,vector<int>& ino,int ib,int ie,map<int,int>& hmap){
    if (pb>pe||ib>ie)
        return NULL;

    TreeNode *temp=new TreeNode;
    temp->val=post[pe];
    int findat=hmap[post[pe]];
    int n=findat-ib;

    temp->left = makeTree(post,pb,pb+n-1,ino,ib,findat-1,hmap);
    temp->right = makeTree(post, pb+n, pe-1 ,ino, findat+1,ie,hmap );
    return temp;
}

void answer(){
    int n,t;
    cin>>n;
    vector<int> in;
    vector<int> post;
    map<int,int> hmap;
    for(int i=0;i<n;i++){
        cin>>t;
        post.push_back(t);
    }

    for(int i=0;i<n;i++){
        cin>>t;
        in.push_back(t);
        hmap[t]=i;
    }
    // TreeNode *root=makeTree(pre,0,pre.size()-1,in,0,in.size()-1);
    TreeNode *root=makeTree(post,0,post.size()-1,in,0,in.size()-1,hmap);

    preOrder(root);    
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