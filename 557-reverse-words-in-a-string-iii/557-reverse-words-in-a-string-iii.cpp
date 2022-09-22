class Solution {
public:
    string reverse(string &s)
    {
        int i = 0 , j = s.size()-1;
        while(i<=j)
            swap(s[i++] , s[j--]);
        return s;
    }
    string reverseWords(string s) {
        
        string ans = "";
        string sub="";        
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == ' ')
            {   
                ans += reverse(sub);
                ans += " ";
                sub = "";
            }
            else
            {
                sub+=s[i];
            }
        }
        
        ans += reverse(sub);
        return ans;
    }
};