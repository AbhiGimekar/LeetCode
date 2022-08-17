class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> s = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        
        set<string> ans;
        
        for(auto i:words)
        {
            string temp = "";
            for(auto j:i)
            {
                temp += (s[j-'a']);
                
            }
            ans.insert(temp);
        }
        
        return ans.size();
        
    }
};