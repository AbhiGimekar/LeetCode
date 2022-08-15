class Solution {
public:
    vector<int> arr[35];                      // constraints
    Solution(){
    for(int i = 0; i < 35; i++)
    {
        for(int j = 0; j < i + 1; j++)
            arr[i].push_back(0);                // Preprocessing - filling pascal matrix with zeros
    }
    }
    int helper(int i, int j)
    {
        if(j == 0 || i == j){
            if(arr[i][j] == 0)                               //  Storing values in matrix for later usage;
                arr[i][j] = 1;
            return arr[i][j];
        }
        if(arr[i][j] == 0)                                    //    If the value is yet to be calculated;
        arr[i][j] = helper(i - 1,j - 1) + helper(i - 1, j);   //    Storing values 
        return arr[i][j];                                     //    using stored values to remove repetition 
    }
    vector<int> getRow(int rowIndex) {
        for(int i = 0; i <= rowIndex; i++)
        {
            helper(rowIndex,i);                            //   calculation of col 0 to rowIndex + 1
        }
        return arr[rowIndex]; 
    }
};