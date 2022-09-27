class Solution {
public:
    string pushDominoes(string s) {
        
        int n = s.size(), l = -1, r = -1;
        for(int i= 0; i <= n; ++i) {
            if(i == n || s[i] == 'R') {
                if (l != r)
                    for(int j = r; j < i; s[j++] = 'R');
                r = i;
            }
            else if (s[i] == 'L'){
                if (l == r)
                    for(int j = l + 1; j < i; s[j++] = 'L');
                else 
                    for(int j = r + 1, k = i - 1; j < k; s[j++] = 'R', s[k--] = 'L');
                l = r = i;
            }
        }
        
        
        return s;
    }
};