class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totalTime = 0 ;
        int n = neededTime.size();
        int i=0 , j = 0;
        
        while(i<n && j<n)
        {
            int curTotal = 0 , curMax = 0;
            while(j<n && colors[i] == colors[j]){
                curTotal += neededTime[j];
                curMax = max(curMax , neededTime[j]);
                j++;
            }
            
            totalTime += curTotal - curMax;
            i = j;
        }
        
        return totalTime;
    }
};