#include <array>
#include <string>

class TrieNode {
public:
    std::array<TrieNode*, 26> letters;
    bool is_end;

    TrieNode() {
        letters = {};
        is_end = false;
    }

    TrieNode* insert(char c) {
        int i = char(c) - char('a');
        letters[i] = new TrieNode();
        return letters[i];
    }

    bool exists(char c) {
        int i = char(c) - char('a');
        return letters[i] != nullptr;
    }

    TrieNode* at(char c) {
        int i = char(c) - char('a');
        return letters[i];
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
        auto curr = root;
        for (auto c: word) {
            if (curr -> exists(c)) {
                curr = curr -> at(c);
            } else {
                curr = curr -> insert(c);
            }
        }
        curr -> is_end = true;
    }
    
    bool search(std::string word) {
        auto curr = root;
        for (auto c: word) {
            if (!(curr -> exists(c))) return false;
            curr = curr -> at(c);
        }
        return curr -> is_end;
    }
    
    bool startsWith(std::string prefix) {
        auto curr = root;
        for (auto c: prefix) {
            if (!(curr -> exists(c))) return false;
            curr = curr -> at(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */