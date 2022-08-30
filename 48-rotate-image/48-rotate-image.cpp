class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        reverse(matrix.begin() , matrix.end());
        
        // for(auto i:matrix)
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<"\n";
        // }
        
        for(int i = 0 ; i<matrix.size() ; i++){
            for(int j = i+1 ; j<matrix[0].size() ;  j++){
                // cout<<matrix[i][j]<<' '<<matrix[j][i]<<"\n";
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }
};