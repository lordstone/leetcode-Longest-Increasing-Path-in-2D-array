class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>> arr (m, vector<int> (n, -1));
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(arr[i][j] == -1)
                    arr[i][j] = findMaxLength(matrix, i, j, arr);
            }
        }
        int max = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(arr[i][j] > max) max = arr[i][j];
            }
        }
        return max;
    }
    
    int findMaxLength(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& arr){
        //traverse he four firections: up down left right
        if(arr[i][j] != -1) return arr[i][j];
        int cellVal = matrix[i][j];
        matrix[i][j] = INT_MIN; // make it not valid for in-depth visits
        int max = 1;
        if(i > 0 && (matrix[i-1][j] != INT_MIN)){// from left
            if(matrix[i-1][j] > cellVal){
                int tmp = findMaxLength(matrix, i-1,j,arr) + 1;
                if(tmp > max) max = tmp;
            }
        }
        if(i < matrix.size() - 1 && (matrix[i+1][j] != INT_MIN)){ // from right
            if(matrix[i+1][j] > cellVal){
                int tmp = findMaxLength(matrix, i+1,j,arr) + 1;
                if(tmp > max) max = tmp;
            }
        }
        if(j > 0 && (matrix[i][j-1] != INT_MIN)){ // from top
            if(matrix[i][j - 1] > cellVal){
                int tmp = findMaxLength(matrix, i,j-1,arr) + 1;
                if(tmp > max) max = tmp;
            }
        }
        if(j < matrix[0].size() - 1  && (matrix[i][j + 1] != INT_MIN)){ // from bottom
            if(matrix[i][j + 1] > cellVal){
                int tmp = findMaxLength(matrix, i,j+1,arr) + 1;
                if(tmp > max) max = tmp;
            }
        }
        matrix[i][j] = cellVal;
        return max;
    }
    
    
};
