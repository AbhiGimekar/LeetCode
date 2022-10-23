class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // let m = missing , d = duplicate
        // diff = m - d
        // squareDiff = m*m - d*d
        // sum = m+d ==> squareDiff/diff
        //           ==> (m+d)(m-d)/(m-d)
        //      sum  ==> (m+d)
        // m = (sum+diff)/2
        // d = (sum-diff)/2
        
        long long diff = 0 , squareDiff = 0;
        for(int i=0 ; i<nums.size(); i++)
        {
            diff += (i+1) - nums[i];
            squareDiff += (i+1)*(i+1) - nums[i]*nums[i];
        }
        
        int sum = squareDiff/diff;
        return {int((sum-diff)/2) , int((sum+diff)/2)};    
    }
};