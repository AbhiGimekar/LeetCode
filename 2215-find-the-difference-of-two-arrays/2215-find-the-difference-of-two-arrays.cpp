class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> ans;
        set<int> temp;
        
        for(int i=0 ; i<nums1.size() ; i++)
        {
            bool flag = false;
            for(int j=0 ; j<nums2.size() ; j++)
            {
                if(nums1[i] == nums2[j]){
                    flag = true;
                }
            }
            
            if(flag == false)
                temp.insert(nums1[i]);
        }
        
        vector<int> cur;
        for(auto i:temp)
            cur.push_back(i);
        
        ans.push_back(cur);
        
        cur.clear() ; temp.clear();
        
        for(int i=0 ; i<nums2.size() ; i++)
        {
            bool flag = false;
            for(int j=0 ; j<nums1.size() ; j++)
            {
                if(nums2[i] == nums1[j]){
                    flag = true;
                }
            }
            
            if(flag == false)
                temp.insert(nums2[i]);
        }
        
        for(auto i:temp)
            cur.push_back(i);
        
        ans.push_back(cur);
        
        return ans;
    }
};