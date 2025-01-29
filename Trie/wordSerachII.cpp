// leetcode - 212 - Important asked in many companies 
// link - https://leetcode.com/problems/word-search-ii/

/*

class TrieNode {
public:
    string word;
    bool isEnd;
    vector<TrieNode*> child;

    TrieNode() : word(""), isEnd(false), child(26, nullptr) {};
};
class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insertWord(string& word) {
        TrieNode* crawler = root;

        for (auto& ch : word) {

            if (crawler->child[ch - 'a'] == NULL) {
                crawler->child[ch - 'a'] = new TrieNode();
            }

            crawler = crawler->child[ch - 'a'];
        }

        crawler->word = word;
        crawler->isEnd = true;
    }

    ~Trie() {
        deleteTrie(root); // destructor to free memory
    }

private:
    void deleteTrie(TrieNode* node) {
        if (!node)
            return;
        for (TrieNode* childNode : node->child) {
            deleteTrie(childNode);
        }
        delete node;
    }
};

class Solution {
    vector<string> result;
    int n, m;

    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* root) {

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$' ||
            root->child[board[i][j] - 'a'] == NULL)
            return;

        root = root->child[board[i][j] - 'a'];

        if (root->isEnd) {
            result.push_back(root->word);
            root->word = "";
            root->isEnd = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {

            int i_ = i + dir[0];
            int j_ = j + dir[1];

            dfs(i_, j_, board, root);
        }
        board[i][j] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        n = board.size();
        m = board[0].size();

        Trie* trieNode = new Trie();

        for (auto& word : words) {
            trieNode->insertWord(word);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = board[i][j];
                if (trieNode->root->child[ch - 'a'] == NULL)
                    continue;
                dfs(i, j, board, trieNode->root);
            }
        }
        return result;
    }
};


*/