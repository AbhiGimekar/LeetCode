class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> required(26,0) , have(26,0);
        
        for(auto i:ransomNote)
        {
            required[i - 'a']++;
        }
        
        for(auto i:magazine)
        {
            have[i - 'a']++;
        }
        
        for(int i=0 ; i<26 ; i++)
        {
            if(required[i] > have[i])
                return false;
        }
        
        return true;
    }
};