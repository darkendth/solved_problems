class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> km(1001,0);
        for (auto it:trips){
            km[it[1]] += it[0];
            km[it[2]] -= it[0];
        }
        int p=0;
        for (auto it:km){
            p += it;
            if (p>capacity)
                return false;
        }
        return true;
    }
};