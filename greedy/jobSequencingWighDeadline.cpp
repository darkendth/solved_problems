# include <iostream>
#include <bits/stdc++.h>
#include <typeindex>
using namespace std;

struct Node{
    int deadline;
    int profit;
};
typedef struct Node Node;


bool comparator(Node j1,Node j2){
    if (j1.profit>j2.profit)
        return true;
    else 
        return false;
}


pair<int,int> jobSequencing(vector<int> deadline,vector<int> profit){
    int n=deadline.size();
    vector<Node> jobs;
    Node job;
    int dl=0;
    for (int i=0;i<n;i++){
        job.deadline=deadline[i];
        job.profit=profit[i];
        jobs.push_back(job);
        dl = max(dl,job.deadline);
    }
    sort(jobs.begin(),jobs.end(),comparator);
    int total_profit=0;
    int num_of_jobs=0;
    vector<int> job_seq(dl+1);
    for (int j=dl;j>0;j--){
        for (int i=0;i<jobs.size();i++){
            // cout<<jobs[i].deadline<<endl;
            if (jobs[i].deadline>=j){
                cout<<"in\n";
                total_profit += jobs[i].profit;
                num_of_jobs++;
                auto it=jobs.begin()+i;
                jobs.erase(it);
                break;
            }
        }
        // cout<<j<<endl;
    }
    return {num_of_jobs,total_profit};
}

void answer(){
    int n;
    cin>>n;
    vector<int> deadline,profit;
    int t;
    for (int i=0;i<n;i++){
        cin>>t;
        deadline.push_back(t);
    }
    for (int i=0;i<n;i++){
        cin>>t;
        profit.push_back(t);
    }
    pair<int,int> res = jobSequencing(deadline, profit);
    cout<<res.first<<" "<<res.second;
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