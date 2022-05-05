class Solution {
public:
    
//     int f(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp)
//     {
//         if(i < 0 ) return j+1;
//         if(j < 0 ) return i+1;
//         if(dp[i][j] != -1 ) return dp[i][j];
        
//         if(s1[i] == s2[j]) return dp[i][j] = f(s1 , s2 , i-1 , j-1 , dp);
        
//         return dp[i][j] =  1 + min(f(s1 , s2 , i-1 ,j , dp), 
//                    min(f(s1 , s2 , i , j-1 , dp),
//                        f(s1 , s2 , i-1 , j-1 , dp)));
        
//     }
    
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        
        vector<int> prev(m+1 , 0) , cur(m+1 , 0);
        
        for(int j = 0 ; j<=m ; j++) prev[j] = j;
        
        for(int i=1 ; i<=n ; i++)
        {   
            cur[0] = i;
            for(int j=1 ; j<=m ; j++)
            {
                if(s1[i-1] == s2[j-1])
                    cur[j] = prev[j-1];
                else
                    cur[j] = 1 + min(prev[j] , min(cur[j-1] , prev[j-1]));
            }
            
            prev = cur;
        }
        
        return prev[m];
    }
};