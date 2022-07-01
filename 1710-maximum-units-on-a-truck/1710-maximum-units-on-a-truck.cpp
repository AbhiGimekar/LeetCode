class Solution {
public:
    
    static bool comp (vector<int> &a , vector<int> &b){
            return (a[1] > b[1]) || (a[1] == b[1] && a[0] > b[0]);
        }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(begin(boxTypes) , end(boxTypes) , comp);
        
        int total = 0 , ans = 0;
        
        for(auto i:boxTypes)
        {
            if(total + i[0] <= truckSize)
            {
                ans += (i[0] * i[1]);
            }
            else if(total + i[0] > truckSize)
            {
                int diff = truckSize - total;
                ans += (diff * i[1]);
                break;
            }
            total += i[0];
        }
        
        return ans;
    }
    
};