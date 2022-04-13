class Solution {
public:
    unordered_map<int,int> mp;
    
    int climbStairs(int n) {
        
        if(mp.find(n) != mp.end()) return mp[n];
        
         int result = 0;
        
         if (n == 0) result = 0;
         else if (n == 1) result= 1; 
         else if (n == 2) result = 2; 
         else result = climbStairs(n-1) + climbStairs(n-2); 
         
         mp[n]=result;
        
         return result;
    }
};