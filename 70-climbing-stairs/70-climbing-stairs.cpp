class Solution {
public:
    
    int climbStairs(int n) {
        
        if(n<=2)
            return n;
        
        int one = 2;
        int two = 1;
        int total = 0;
        
        for(int i=2 ; i<n ; i++)
        {
            total = one + two;
            two = one;
            one = total;
        }
        
        return  total;
    }
};