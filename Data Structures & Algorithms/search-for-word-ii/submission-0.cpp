class TrieNode {
public:
    TrieNode* children[26] = {};
    string word = "";
};

class Solution {
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;
        
        node = node->children[ch - 'a'];
        if (node->word != "") {
            res.push_back(node->word);
            node->word = ""; // Prevent duplicates
        }
        
        board[r][c] = '#';
        int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size())
                dfs(board, nr, nc, node, res);
        }
        board[r][c] = ch; // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->word = w;
        }
        
        vector<string> res;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, res);
        return res;
    }
};