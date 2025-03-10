class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(),i,j;
        
        int maxCur = 0, maxSoFar = 0;
        
        for(int i = 1; i < n ; i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
            //cout<<maxCur<<" "<<maxSoFar<<"\n";
        }
        return maxSoFar;
        
        
    }
};