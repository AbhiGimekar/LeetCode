class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int cnt[26] = {0};
        
        for(auto i:sentence)cnt[i-'a']++;
        
        for(int i=0 ;  i<26 ; i++)
        {
            if(cnt[i] == 0)return false;
        }
        
        return true;
    }
};