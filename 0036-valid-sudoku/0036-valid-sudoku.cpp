class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j) {
        vector<int> v1(10, 0);
        vector<int> v2(10, 0);
        vector<int> v3(10, 0);
        for (int k=0; k<9; k++) {
            if (board[i][k] != '.') {
                v1[board[i][k]-'0']++;
            }
        }
        for (int k=0; k<9; k++) {
            if (board[k][j] != '.') {
                v2[board[k][j]-'0']++;
            }
        }
        for (int x=(i-(i%3)); x<(i-(i%3)+3); x++) {
            for (int y=(j-(j%3)); y<(j-(j%3)+3); y++) {
                if (board[x][y] != '.') {
                    v3[board[x][y]-'0']++;
                }
            }
        }
        for (int k=1; k<=9; k++) {
            if (v1[k] > 1 || v2[k] > 1 || v3[k] > 1) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    bool res = isValid(board, i, j);
                    if (!res) return false;
                }
            }
        }
        return true;
    }
};
