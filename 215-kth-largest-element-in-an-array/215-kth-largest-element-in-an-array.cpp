class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         sort(nums.begin() , nums.end());
        
//         return nums[n - k ];
        
        priority_queue<int> pq;
        
        for(auto &i:nums)
            pq.push(i);
        
        while(k>1){
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};