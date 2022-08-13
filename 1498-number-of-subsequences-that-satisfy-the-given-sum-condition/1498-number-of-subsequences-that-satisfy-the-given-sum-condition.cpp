class Solution {
    int mod = 1e9 + 7;
public:
    
    long long power(long long a, long long b)
    {
        long long result = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return result%mod;
    }

    
    long long numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        
        long long ans = 0;
        long long start = 0 , end = nums.size()-1;
        while(start <= end)
        {
            if(nums[start] + nums[end] <= target)
            {
                ans += (power(2,end-start));
                ans%=mod;
                start++;
            }
            else
            {
                end--;
            }
        }
        
        return ans;
    }
};