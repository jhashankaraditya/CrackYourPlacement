class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int neighbours=0;
                if (i-1>=0 && j-1>=0 && (board[i-1][j-1]==1 || board[i-1][j-1]==7)) {
                    neighbours++;
                }
                if (i-1>=0 && (board[i-1][j]==1 || board[i-1][j]==7)) {
                    neighbours++;
                }
                if (i-1>=0 && j+1<m && (board[i-1][j+1]==1 || board[i-1][j+1]==7)) {
                    neighbours++;
                }
                if (j-1>=0 && (board[i][j-1]==1 || board[i][j-1]==7)) {
                    neighbours++;
                }
                if (j+1<m && (board[i][j+1]==1 || board[i][j+1]==7)) {
                    neighbours++;
                }
                if (i+1<n && j-1>=0 && (board[i+1][j-1]==1 || board[i+1][j-1]==7)) {
                    neighbours++;
                }
                if (i+1<n && (board[i+1][j]==1 || board[i+1][j]==7)) {
                    neighbours++;
                }
                if (i+1<n && j+1<m && (board[i+1][j+1]==1 || board[i+1][j+1]==7)) {
                    neighbours++;
                }
                if (board[i][j]==0 && neighbours==3) {
                    board[i][j]=8;
                }
                else if (board[i][j]==1) {
                    if (neighbours<2) {
                        board[i][j]=7;
                    }
                    else if (neighbours==2 || neighbours==3) {
                        board[i][j]=1;
                    }
                    else if (neighbours>3) {
                        board[i][j]=7;
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j]>1) {
                    board[i][j]-=7;
                }
            }
        }
    }
};
