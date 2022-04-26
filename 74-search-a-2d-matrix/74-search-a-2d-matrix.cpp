class Solution {
public:
    
    //Another way to took at it is: lets say you have a matrix M with 4 rows and 3 columns.
    //When we want to access M[2][1], the way the memory address is calculated is 2*3+1 = 7. 
    //so you are just reversing the calculation , row number is given by 7/3 = 2,
    //and column is the offset in that row so for 7th element it is 7%3 = 1.
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end = m*n - 1;
        
        while(start != end)
        {
            int mid = start + (end - start) / 2;
            
            if(matrix[mid/n][mid%n] < target)
                start = mid + 1;
            else
                end = mid;
        }
        
        return matrix[end/n][end%n] == target;
    }
};