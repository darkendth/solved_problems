
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

class Solution {
public:
    
    void func(int i,int n,int p,int e,string& str,vector<string>& res){
        if (p<e)
            return ;
        
        if (i==n){
            if (p==e)
                res.push_back(str);
            cout<<str<<endl;
            return ;
        }
        
        if(p<n/2){
            str += "(";
            func(i+1,n,p+1,e,str,res);
            str.pop_back();    
        }
        str+= ")";
        func(i+1,n,p,e+1,str,res);
        str.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        string str="(";
        vector<string> res;
        func(1,n*2,1,0,str,res);
        return res;
    }
};