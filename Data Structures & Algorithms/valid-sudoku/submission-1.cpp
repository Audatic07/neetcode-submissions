class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<int, unordered_set<char>> sq;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                char cell=board[i][j];
                if(cell=='.') continue;
                if(row[i].contains(cell) || col[j].contains(cell) || sq[(i/3)*3+(j/3)].contains(cell)){
                    return false;
                }
                row[i].insert(cell);
                col[j].insert(cell);
                sq[(i/3)*3+(j/3)].insert(cell);
            }
        }
        return true;
    }
};
