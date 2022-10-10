
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
//  typically using all the original letters exactly once.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hmap;
        
        vector<vector<string>> res;
        for (int i=0;i<strs.size();i++){
            string opt;
            map <char,int> freq;
            for (auto it:strs[i]){
                freq[it]++;
            }
            for (auto it:freq){
                // cout<<it.first<<" "<<it.second<<endl;
                opt += it.first+to_string(it.second);
            }
            hmap[opt].push_back(strs[i]);
        }
        for (auto it:hmap){
            res.push_back(it.second);
        }
        return res;
    }
};