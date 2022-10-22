class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> map(128,0);
        for(auto i:t)map[i]++;
        
        int counter = t.size() , left = 0 , right = 0 , minLength = INT_MAX , head;
        
        while(right < s.size())
        {
            if(map[s[right++]]-- > 0)counter--;
            while(counter == 0)
            {
                if(right - left < minLength)
                {
                    minLength = right - left;
                    head = left;
                }
                if(map[s[left++]]++ == 0)counter++;
            }
        }
        
        return minLength == INT_MAX ? "" : s.substr(head , minLength);
    }
};