# include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isSafe(int row,int col,vector<string>& board){
    int r=row;
    int c=col;
    
    while(r>=0&&col>=0){
        if (board[r][c]=='Q')
            return false;
        r--;
        c--;
    }
    
    r=row;
    c=col;
    while(c>=0){
        if (board[row][c]=='Q')
            return false;
        c--;
    }

    r=row;
    c=col;
    while(r<board.size()&&col>=0){
        if (board[r][c]=='Q')
            return false;
        r++;
        c--;
    }
    return true;
}

void nqueens(int n,int col,vector<vector<string>>& res,vector<string>& board){
    if (col==n){
        res.push_back(board);
        return ;
    }

    for (int i=0;i<n;i++){
        if (isSafe(i,col,board)){
            board[i][col]='Q';
            nqueens(n, col+1, res, board);
            board[i][col]='.';
        }
    }
}

void answer(){
    int n;
    cin>>n;
    vector<string> board(n);
    vector<vector<string>> res;
    string s(n,'.');
    for (int i=0;i<n;i++)
        board[i]=s;

    nqueens(n,0,res,board);

    for (int i=0;i<n;i++){
        cout<<i<<".\n";
        for (int j=0;j<n;j++){
            cout<<res[i][j]<<endl;
        }
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