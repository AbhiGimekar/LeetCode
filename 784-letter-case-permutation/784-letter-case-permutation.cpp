class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        
        vector<string> ans;
        backTrack(0 , s , ans);
        return ans;
    }
    
    void backTrack(int i , string &s , vector<string> &ans)
    {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        
        // save initial value
        char c = s[i];
        // path1: toggle lower/upper case
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backTrack(i+1, s, ans);
        // path2: reset back(NOT go to this path if c is digit)
        if (isalpha(c)) {
            s[i] = c;
            backTrack(i+1, s , ans);
        }
    }
};