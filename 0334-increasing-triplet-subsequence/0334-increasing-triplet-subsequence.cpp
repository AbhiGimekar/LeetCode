class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int x1 = INT_MAX , x2 = INT_MAX;
        for(auto x:nums)
        {
            if(x <= x1)
                x1 = x;
            else if(x <= x2)
                x2 = x;
            else
                return true;
        }
        
        return false;
    }
};