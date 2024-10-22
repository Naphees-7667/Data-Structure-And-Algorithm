#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* child[26];
    bool isTerminal;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isTerminal = false;
    } 
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if(node->child[index] == nullptr){
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isTerminal = true;
    }

    void printSuggestions(TrieNode* curr,vector<string>& output,string& temp){

        if(curr == nullptr)return;

        if(curr->isTerminal == true){
            output.push_back(temp);
        }

        for(int i=0;i<26;i++){
            if(curr->child[i] != nullptr){
                char ch = char (i + 'a');
                temp.push_back(ch);
                printSuggestions(curr->child[i],output,temp);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> getSuggestions(string word){
        vector<vector<string>> result;
        TrieNode* prev = root;
        string temp = "";
        for(int i=0;i<word.size();i++){
            int lastChar = word[i] - 'a';
            temp.push_back(word[i]);
            vector<string> output;
            TrieNode* curr = prev->child[lastChar];
            if(curr == nullptr)break;
            printSuggestions(curr,output,temp);
            result.push_back(output);
            prev = curr;
        }
        return result;
    }
};

int main() {
    // Example test case
    int n = 3;
    string contacts[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    string query = "geeips";

    Trie* trie = new Trie();

    for (auto it : contacts) {
        trie->insert(it);
    }

    vector<vector<string>> res =  trie->getSuggestions(query);

    for (auto it : res) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }
    
    return 0;
}