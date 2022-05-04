class Solution {
public:
    int trap(vector<int>& height) {
     
        int n = height.size();
        vector<int> prefix(n,0) , suffix(n,0);
        
        int leftMax = 0;
        for(int i=0 ; i<n ; i++){
            prefix[i] = max(height[i] , leftMax);
            leftMax = max(leftMax , height[i]);
        }
        
        int rightMax = 0;
        for(int i=n-1 ; i>=0 ;i--)
        {
            suffix[i] = max(rightMax , height[i]);
            rightMax = max(rightMax , height[i]);
        }
        
        int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            ans += (min(prefix[i] , suffix[i]) - height[i]);
        }
        
        return ans;
    }
};