class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, int m, int n, string word, int k, int size, vector<vector<bool>>& isVisited) {
        if (k == size) return true;
        if (i < 0 || i == m || j < 0 || j == n) return false;
        if (isVisited[i][j]) return false;
        if (board[i][j] != word[k]) return false;
        isVisited[i][j] = true;
        bool res = find(board, i, j-1, m, n, word, k+1, size, isVisited) ||
            find(board, i-1, j, m, n, word, k+1, size, isVisited) ||
            find(board, i, j+1, m, n, word, k+1, size, isVisited) ||
            find(board, i+1, j, m, n, word, k+1, size, isVisited);
        isVisited[i][j] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int size = word.length();
        vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (find(board, i, j, m, n, word, 0, size, isVisited)) return true;
            }
        }
        return false;
    }
};
