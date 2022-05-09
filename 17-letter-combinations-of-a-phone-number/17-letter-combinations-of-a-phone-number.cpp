class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> str = {"" ,"" , "abc" , "def" , "ghi" , "jkl" ,"mno" , "pqrs" , "tuv" , "wxyz"};
        vector<string> ans;
        
        if(digits.size()==0)return ans;
        
        ans.push_back("");
        
        for(int i=0 ; i<digits.size() ; i++){
            
            vector<string> temp;
            string s = str[digits[i] - '0'];
            
            for(int j=0 ; j<s.size() ; j++){
                for(int k=0 ; k<ans.size() ; k++){
                    temp.push_back(ans[k] + s[j]);
                }
            }
            
            ans = temp;
        }
        
        return ans;
    }
};