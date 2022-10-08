# include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s){
    int n=s.size();
    for (int i=0;i<n/2;i++){
        if (s[i]!=s[n-i-1])
            return false;
    }
    return true;
}

void PalindromePartition(string s,int index,vector<string>& substr,vector<vector<string>>& res){
    if (index==s.size()){
        res.push_back(substr);
        return ;
    }
    cout<<index<<endl;
    cout<<"size "<<s.size()<<endl;
    for (int i=index+1;i<=s.size();i++){
        string sub=s.substr(index,i-index);
        cout<<sub<<endl;
        if (isPalindrome(sub)){
            substr.push_back(sub);
            PalindromePartition(s, i, substr, res);
            substr.pop_back();
        }   
    }
}

void answer(){
    string str;
    cin>>str;
    cout<<"str "<<str<<endl;
    vector<string> substr;
    vector<vector<string>> res;
    PalindromePartition(str, 0, substr, res);
    for (int i=0;i<res.size();i++){
        cout<<"{";
        for (int j=0;j<res[i].size();j++)
            cout<<"'"<<res[i][j]<<"',";
        cout<<"}\n";
    }
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