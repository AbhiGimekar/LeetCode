class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        
        if(a.size()==0)return 0;
        
        sort(begin(a) , end(a));
        // for(auto i:a)cout<<i<<" ";
        int cnt = 1 , ans=-1;
        
        for(int i=1 ;  i<a.size() ; i++)
        {
            if(a[i] - a[i-1] == 1)
            {
                cnt++;
            }
            else if(a[i] - a[i-1] == 0)continue;
            else
            {
                ans = max(ans, cnt);
                cnt = 1 ;
            }
        }
        
        ans = max(ans,cnt);
        
        return ans;
    }
};