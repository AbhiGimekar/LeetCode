class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long> mp;
        int n = views.size();
        
        for(int i=0; i<n; i++){
            mp[creators[i]] += views[i];
        }
        
        long long maxi=-1e9;
        for(auto i:mp)
            maxi = max(maxi,i.second);
        
        vector<string> ans;
        for(auto i:mp){
            if(i.second == maxi)
                ans.push_back(i.first);
        }
        
        // for(auto i:ans)cout<<i<<' ';
        // cout<<"\n";
        
        unordered_map<string, pair<string,int>> m;
        
        for(int i=0; i<n; i++)
        {
            if(m.find(creators[i]) != m.end()){
                int view = m[creators[i]].second;
                if(view < views[i]){
                    m[creators[i]] = {ids[i],views[i]};
                }
                else if(view == views[i]){
                    string temp = m[creators[i]].first;
                    if(temp > ids[i]){
                        temp = ids[i];
                    }
                    m[creators[i]] = {temp, views[i]};
                }
            }
            else{
                m[creators[i]] = {ids[i],views[i]};
            }
        }
        
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
        // }
        
        vector<vector<string>> res;
        
        for(int i=0; i<ans.size(); i++)
        {
            res.push_back({ans[i], m[ans[i]].first});
        }
        
        return res;
    }
};