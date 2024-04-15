#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Trie {
   public:
    vector<Trie*> children;
    bool isEnd;
    Trie() : children(26, nullptr), isEnd(false){};

    void insert(string word) {
        Trie* currentNode = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new Trie();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEnd = true;
    }

    bool search(string word) {
        Trie* currentNode = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isEnd;
    }
};

class Solution {
   public:
    // dp[j] = dp[i] && check(s[i+1, j])
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        Trie root;
        for (int i = 0; i < wordDict.size(); i++) root.insert(wordDict[i]);
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[j] && root.search(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};