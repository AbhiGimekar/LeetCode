class Solution {
public:
    int xx(vector<int> &nums){ 
        int x=0;
        for(auto it:nums)x^=it;
        return x;
    }
    
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int x1=xx(nums1), x2=xx(nums2);
        int n=nums1.size(), m=nums2.size();
        
        if(n%2==0 && m%2==0)return 0; //both even
        else if(n%2 && m%2==0){ // odd,even
            return x2;
        }
        else if(n%2==0 && m%2){ // even,odd
            return x1;
        }
        
        return (x1^x2); // odd,odd
    }
};