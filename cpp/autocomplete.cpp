
#include<iostream>

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
        struct TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord;
};

bool isEmpty(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* getNode() {
    struct TrieNode* node = new TrieNode;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->isEndOfWord = false;
    return node;
}

void insert(TrieNode* root, string key) {
    struct TrieNode* cur = root;

    for (int i = 0; i < key.length(); i++) { 
        int k = key[i] - 'a';
        if (!cur->children[k]) {
            cur->children[k] = getNode();
        }
        cur = cur->children[k];
    }
    cur->isEndOfWord = true;
}

bool search(TrieNode* root, string key) {
    TrieNode* cur = root;

    for(int i = 0; i < key.length(); i++) {
        int idx = key[i] - 'a';
        if (cur->children[idx] == NULL)
            return false;
        cur = cur->children[idx];
    }

    return (cur != NULL && cur->isEndOfWord);
}

TrieNode* remove(TrieNode* root, string key, int depth = 0) {
    if (!root) return NULL;

    if (depth == key.size()) {
        
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if(isEmpty(root)) {
            delete root;
            root = NULL;
        }
        
        return root;
    }

    int idx = key[depth] - 'a';
    root->children[idx] = remove(root->children[idx], key, depth + 1);

    if(isEmpty(root) && root->isEndOfWord == false) {
        delete root;
        root = NULL;
    }

    return root;
}


bool isLastNode(TrieNode* node) {
    
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            return false;
    return true;
}

void suggestionsRec(TrieNode* root, string currPrefix) {
    
    if (root->isEndOfWord)
        cout << currPrefix << endl;

    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            currPrefix.push_back((int)'a' + i);
            suggestionsRec(root->children[i], currPrefix);
            currPrefix.pop_back();
        }
    }
}

int printAutoSuggestions(TrieNode* root, const string query) {
    
    struct TrieNode* cur = root;
    int length = query.length();

    for (int i = 0; i < length; i++) {

        int index = CHAR_TO_INDEX(query[i]);
        if (!cur->children[index])
            return 0;

        cur = cur->children[index];
    }

    bool isWord = (cur->isEndOfWord == true);
    bool isLastWord = isLastNode(cur);

    if (isWord && isLastWord) {
        cout << query << endl;
        return -1;
    }

    if (!isLastWord) {
        string prefix = query;
        suggestionsRec(cur, prefix);
        return 1;
    }
}

int main() {

    struct TrieNode* root = getNode();
    string words[10] = {"hello", "dog", "hell", "cat", "a", "hel", "help", "helps", "helping", "helloworld"};

    for (int i = 0; i < 10; i++) {
        insert(root, words[i]);
    }

    int comp = printAutoSuggestions(root, "hel");

    if (comp == -1)
        cout << "No other strings found with this prefix" << endl;
    else if (comp == 0)
        cout << "No string found" << endl;

    return 0;
}
