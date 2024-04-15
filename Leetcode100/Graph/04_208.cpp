#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Trie is a data structure used for efficient prefix searching in a
 *        collection of strings.
 */
class Trie {
    // Members
    /**
     * @brief A vector of pointers to Trie objects representing the child
     *        nodes of the current node.
     */
    vector<Trie*> childNodes;
    /**
     * @brief A boolean indicating whether the current node represents the end
     *        of a word.
     */
    bool isWordEnd;

    // Methods
    /**
     * @brief Searches for a prefix in the trie and returns the node
     * representing the deepest node with the prefix.
     *
     * @param prefix The prefix to search for.
     *
     * @return A pointer to the deepest node with the prefix, or nullptr if the
     *         prefix is not present in the trie.
     */
    Trie* searchPrefix(const string& prefix) {
        Trie* currentNode = this;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->childNodes[index] == nullptr) {
                return nullptr;
            }
            currentNode = currentNode->childNodes[index];
        }
        return currentNode;
    }

   public:
    /**
     * @brief Constructs a Trie object.
     */
    Trie() : childNodes(26, nullptr), isWordEnd(false) {}

    /**
     * @brief Inserts a word into the trie.
     *
     * @param word The word to insert.
     */
    void insert(const string& word) {
        Trie* currentNode = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->childNodes[index] == nullptr) {
                currentNode->childNodes[index] = new Trie();
            }
            currentNode = currentNode->childNodes[index];
        }
        currentNode->isWordEnd = true;
    }

    /**
     * @brief Searches for a word in the trie.
     *
     * @param word The word to search for.
     *
     * @return True if the word is present in the trie, false otherwise.
     */
    bool search(const string& word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->isWordEnd;
    }

    /**
     * @brief Checks if the trie has any word starting with the given prefix.
     *
     * @param prefix The prefix to check.
     *
     * @return True if the trie has any word starting with the prefix, false
     *         otherwise.
     */
    bool startsWith(const string& prefix) {
        return searchPrefix(prefix) != nullptr;
    }
};
