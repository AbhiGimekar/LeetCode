class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto i:strs)
        {
            string temp = i;
            sort(begin(temp), end(temp));
            mp[temp].push_back(i);
        }
        
        vector<vector<string>> anagram;
        
        for(auto i:mp)
        {
            anagram.push_back(i.second);
        }
        
        return anagram;
    }
};