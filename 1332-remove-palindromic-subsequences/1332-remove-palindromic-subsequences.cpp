class Solution {
public:
    
    
    int removePalindromeSub(string s) {
        
        string a = string(s.rbegin() , s.rend());
        
        if(s == "") return 0;
        if(s == a) return 1;
        else return 2;
    }
};