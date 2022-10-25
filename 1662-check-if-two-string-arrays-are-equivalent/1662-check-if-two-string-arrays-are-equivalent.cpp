class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s = "";
        for(auto i:word1)
        {
            for(auto j:i)
            {
                s+=j;
            }
        }
        
        string t;
        for(auto i:word2)
        {
            for(auto j:i)
            {
                t+=j;
            }
        }
        
        return s == t;
    }
};