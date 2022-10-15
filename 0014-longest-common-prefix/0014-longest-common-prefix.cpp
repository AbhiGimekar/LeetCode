class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int mini = 201;
        for(int i=0 ; i<str.size() ; i++)
        {
            if(str[i].size() < mini) 
                mini = str[i].size();
        }
        string ans = "";
        for(int i=0; i<mini ; i++)
        {   
            set<char> st;
            int j = 0;
            for(j=0 ; j<str.size() ; j++)
            {
                st.insert(str[j][i]);
            }
            
            if(st.size() == 1)ans += str[0][i];
            else break;
        }
        
        return ans;
    }
};