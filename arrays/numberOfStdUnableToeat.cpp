class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> pq;
        int j=0;
        for (auto it:students)
            pq.push(it);
        int rotation=0,t;
        while(!pq.empty()){
            if (rotation>pq.size())
                break;
            if (pq.front()==sandwiches[j]){
                j++;
                pq.pop();
                rotation=0;
            }
            else {
                t=pq.front();
                pq.pop();
                pq.push(t);
                rotation++;
            }
        }
        return pq.size();
    }
};