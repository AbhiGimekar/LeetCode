class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int mn = INT_MAX;
        int ans = 0;
        
        for(int i=0 ; i<n-2 ; i++){
            
            int left = i+1 , right = n - 1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < mn){
                    mn = abs(sum - target);
                    ans = sum;
                }
                
                if(sum < target) left++;
                else if(sum > target) right--;
                else{
                    ans = sum ;
                    i = n - 2;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};