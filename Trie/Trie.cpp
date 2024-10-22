#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode *child[26];
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie
{
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }

    // Insert word into the trie
    void insert(string word){
        TrieNode *node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == NULL){
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(string word){
        TrieNode* node = root;
        for(char c : word){
            int index = c - 'a';
            if(node->child[index] == NULL){
                return false;
            }
            node = node->child[index];
        }
        return node->isEndOfWord;
    }

    // Check if a node is empty (has no children)
    bool isEmpty(TrieNode* node){
        for(int i = 0; i < 26; i++){
            if(node->child[i] != NULL){
                return false;
            }
        }
        return true;
    }

    // Delete a word from the trie
    bool DeleteWordFromTrie(TrieNode* node, string word, int i){
        if(node == NULL){
            return false; // If the node is null, return false
        }

        if(i == word.length()){
            node->isEndOfWord = false;
            return isEmpty(node); // If the node is empty after unmarking, return true to delete
        }

        int index = word[i] - 'a';
        
        if(DeleteWordFromTrie(node->child[index], word, i + 1)){
            delete node->child[index]; // Free the memory of the child node
            node->child[index] = NULL; // Set the pointer to NULL

            // Check if the current node can also be deleted
            return !node->isEndOfWord && isEmpty(node);
        }

        return false;
    }

    // Helper function to delete a word from the trie
    void deleteWord(string word){
        DeleteWordFromTrie(root, word, 0);
    }
};

int main(){

    Trie* tree = new Trie();

    tree->insert("apple");
    tree->insert("appex");
    tree->insert("almond");

    if(tree->search("apple")){ 
        cout << "It exists in the trie data structure\n";
    }
    else {
        cout << "It does not exist in the trie data structure\n";
    }
    
    tree->deleteWord("apple");

    if(tree->search("apple")){ 
        cout << "It exists in the trie data structure\n";
    }
    else {
        cout << "It does not exist in the trie data structure\n";
    }

    return 0;
}
