class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        multiset<int> s(begin(changed), end(changed));
        vector<int> ans;
        
        for (int i = 0; i < changed.size(); i += 2) {
            int n = *s.begin();
            ans.push_back(n);
            
            s.erase(s.begin());
            
            if (s.find(2 * n) == s.end()) return {};
            s.erase(s.find(2 * n));
            
        }
        
        return ans;
        
    }
};