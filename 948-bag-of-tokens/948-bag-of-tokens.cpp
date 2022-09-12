class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin() , tokens.end());
        int left = 0 , right = tokens.size()-1;
        
        int points = 0 , ans = 0;
        
        while(left <= right && (power >= tokens[left] || points>0))
        {
            while(left<=right && power >= tokens[left])
            {
                power -= tokens[left++];
                points++;
            }
            
            ans = max(ans , points);
            
            if(left <= right && points > 0)
            {
                power += tokens[right--];
                points--;
            }
        }
        
        return ans;
    }
};