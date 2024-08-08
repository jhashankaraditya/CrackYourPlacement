class Solution {
    bool solve(vector<vector<char>>& board, string word, int i, int j, int word_idx, vector<vector<bool>> &marked) {
        int n=board.size(), m=board[0].size();
        if (i<0 || i>=n || j<0 || j>=m || word_idx>=word.size()) {
            return 0;
        }
        if (word_idx==word.size()-1 && board[i][j]==word[word_idx]) {
            return 1;
        }
        if (word[word_idx]!=board[i][j]) {
            return 0;
        }
        marked[i][j]=1;
        bool up=0, right=0, down=0, left=0;
        //up
        if (i>0 && !marked[i-1][j]) {
            up=solve(board,word,i-1,j,word_idx+1,marked);
        }
        //down
        if (i<n-1 && !marked[i+1][j]) {
            down=solve(board,word,i+1,j,word_idx+1,marked);
        }
        //left
        if (j>0 && !marked[i][j-1]) {
            left=solve(board,word,i,j-1,word_idx+1,marked);
        }
        //right
        if (j<m-1 && !marked[i][j+1]) {
            right=solve(board,word,i,j+1,word_idx+1,marked);
        }
        marked[i][j]=0;
        return up||left||down||right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool word_present=0;
        int n=board.size(), m=board[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j]==word[0]) {
                    vector<vector<bool>> marked(n,vector<bool>(m,0));
                    word_present=word_present||solve(board,word,i,j,0,marked);
                }
            }
        }
        return word_present;
    }
};
