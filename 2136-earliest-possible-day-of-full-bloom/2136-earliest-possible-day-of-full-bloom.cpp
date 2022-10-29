class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<int> indices(plantTime.size());
        iota(begin(indices), end(indices), 0);
        // for(int i=0; i<indices.size(); i++)
        //     cout<<indices[i]<<" ";
        // cout<<"\n";
        
        sort(begin(indices), end(indices), 
             [&](int i, int j) { return growTime[i] > growTime[j];} );
        
        // for(int i=0; i<indices.size(); i++)
        //     cout<<indices[i]<<" ";
        // cout<<"\n";
        
        int result = 0, curPlantTime = 0;
        for (int i : indices) {
            curPlantTime += plantTime[i];
            result = max(result, curPlantTime + growTime[i]);
        }
        return result;       

    }
};