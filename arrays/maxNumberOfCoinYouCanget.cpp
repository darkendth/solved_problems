class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int mem[10002]={0};
        for (auto it:piles)
            mem[it]++;
        
        int end=10001;
        int res=0;
        int i=n/3;
        while(end>=0&&i>0){
            while(end>=0&&mem[end]==0)
                end--;
            mem[end]--;
            while(end>=0&&mem[end]==0)
                end--;
            // cout<<end<<endl;
            res += end;
            mem[end]--;
            i--;
        }
        return res;
    }
};