class Solution {
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
public:
    
//     void add(int val){
//         if (max_heap.empty()||max_heap.top()>val)
//             max_heap.push(val);
//         else
//             min_heap.push(val);
        
//         if (max_heap.size()+1<min_heap.size()){
//             max_heap.push(min_heap.top());
//             min_heap.pop();
//         }
//         else if (max_heap.size()>min_heap.size()+1){
//             min_heap.push(max_heap.top());
//             max_heap.pop();
//         }
//     }
    
//     double get_median(){
//         if (max_heap.size()==min_heap.size())
//             return max_heap.size()==0?0:(max_heap.top()+min_heap.top())/2.0;
//         else{
//             return max_heap.size()>min_heap.size()?max_heap.top():min_heap.top();
//         }
//     }
    
//     void remove(int val){
//         if (val<get_median())
//             max_heap.erase(max_heap.find(val));
//         else
//             min_heap.erase(min_heap.find(val));
        
//         if (max_heap.size()+1<min_heap.size()){
//             max_heap.push(min_heap.top());
//             min_heap.pop();
//         }
//         else if (max_heap.size()>min_heap.size()+1){
//             min_heap.push(max_heap.top());
//             max_heap.pop();
//         }
            
//     }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // vector<double> res;
        // for (int i=0;i<k;i++){
        //     add(nums[i]);            
        // }
        // double med;
        // for (int i=k-1;i<n;i++){
        //     if (i-k>=0){
        //         remove(nums[i-k]);
        //         add(nums[i]);
        //     }
        //     med = get_median();
        //     res.push_back(med);
        // }
        // return res;
        
        multiset<int> window;
        for (int i=0;i<k;i++)
            window.insert(nums[i]);
        auto med = next(window.begin(),k/2);
        vector<double> medians;
        for (int i=k;i<=nums.size();i++){
            // cout<<"med "<<*med<<endl;
            if (k%2==0){
                double temp = (double(*med)+*prev(med,1))/2.0;
                medians.push_back(temp);
            }
            else
                medians.push_back(*med);
            
            if (i==nums.size())
                break;
            
            // cout<<"1\n";
            window.insert(nums[i]);
            if (nums[i]<*med)
                med--;
            if (nums[i-k]<=*med)
                med++;
            
            window.erase(window.find(nums[i-k]));
        }
        return medians;
        
    }
};