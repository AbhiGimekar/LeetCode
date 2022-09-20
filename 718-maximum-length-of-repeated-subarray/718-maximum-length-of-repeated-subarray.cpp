class Solution {
public:
    
    int fun(int ind1 ,int ind2 , int n , int m , vector<int> &nums1 , vector<int> &nums2)
    {
        if(ind1 > n || ind2>m)return 0;
        
        if(nums1[ind1] == nums2[ind2])
        {
            return  1 + fun(ind1+1 , ind2+1 , n , m , nums1 , nums2);
        }
        else
        {
            return max(fun(ind1+1 , ind2 , n , m , nums1 , nums2) , 
                       fun(ind1 , ind2+1 , n , m , nums1 , nums2));
            
        }
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        int ans = 0;
        for(int i=n-1 ; i>=0 ; i--)
        {
            for(int  j=m-1 ; j>=0 ; j--)
            {
                if(nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    if(ans < dp[i][j]) ans = dp[i][j];
                }
            }
        }
        
        return ans;
        
    }
};