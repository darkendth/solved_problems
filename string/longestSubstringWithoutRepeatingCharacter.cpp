
// 
// Given a string s, find the length of the longest substring without repeating characters.




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0)
            return 0;
        map<char,int> hmap;
        int i=0,j=0;
        int len=0;
        while(i<s.size()){
            if(hmap.find(s[i])==hmap.end()){
                hmap[s[i]]=i;
                len = max(len,i-j+1);
            }
            else{
                if(j>hmap[s[i]]){
                    hmap[s[i]]=i;
                    len = max(len,i-j+1);
                }
                else{
                    j=hmap[s[i]]+1;
                    hmap[s[i]]=i;   
                }
            }
            i++;
        }
        return len;
    }
};