class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> spiral_order;
        vector<vector<int>> marked(n,vector<int>(m,0));
        int i=0, j=0, total_marked=0;
        string direction="Right";
        while (total_marked<n*m) {
            spiral_order.push_back(matrix[i][j]);
            marked[i][j]=1;
            total_marked++;
            if (direction=="Right") {
                if (j+1>=m || (j+1<m && marked[i][j+1])) {
                    direction="Down";
                    i++;
                }
                else j++;
            }
            else if (direction=="Down") {
                if (i+1>=n || (i+1<n && marked[i+1][j])) {
                    direction="Left";
                    j--;
                }
                else i++;
            }
            else if (direction=="Left") {
                if (j<=0 || (j>0 && marked[i][j-1])) {
                    direction="Up";
                    i--;
                }
                else j--;
            }
            else if (direction=="Up") {
                if (i<=0 || (i-1>=0 && marked[i-1][j])) {
                    direction="Right";
                    j++;
                }
                else i--;
            }
        }
        return spiral_order;
    }
};
