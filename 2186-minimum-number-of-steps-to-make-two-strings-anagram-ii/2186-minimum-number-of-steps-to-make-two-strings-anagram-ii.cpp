class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> one(26 , 0) , two(26,0);
        
        for(auto i: s)
            one[i - 'a']++;
        for(auto i: t)
            two[i - 'a']++;
        
        int ans = 0;
        for(int i=0 ; i<26 ; i++)
            ans += (abs(one[i]-two[i]));
        
        return ans;
    }
};