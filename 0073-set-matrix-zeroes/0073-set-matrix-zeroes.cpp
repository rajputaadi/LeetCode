class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_set<int> setrows ;
        unordered_set<int> setcolumn;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    setrows.insert(i);
                    setcolumn.insert(j);
                }
            }
        }

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(setrows.count(i)> 0 || setcolumn.count(j) > 0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};