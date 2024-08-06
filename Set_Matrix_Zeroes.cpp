class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> rows;
        unordered_map<int,bool> cols;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j]==0) {
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for (auto row:rows) {
            int curr_row=row.first;
            for (int i=0; i<matrix[0].size(); i++) {
                matrix[curr_row][i]=0;
            }
        }
        for (auto col:cols) {
            int curr_col=col.first;
            for (int i=0; i<matrix.size(); i++) {
                matrix[i][curr_col]=0;
            }
        }
    }
};
