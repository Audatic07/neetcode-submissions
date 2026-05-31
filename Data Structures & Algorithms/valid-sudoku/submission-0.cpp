class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> square(9);
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == '.') continue;
                char c=board[i][j];
                int sq_idx= (i/3)*3 + j/3;
                if(rows[i].count(c) || cols[j].count(c) || square[sq_idx].count(c)) return false;
                rows[i].insert(c);
                cols[j].insert(c);
                square[sq_idx].insert(c);
            }
        }
        return true;
    }
};
