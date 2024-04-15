#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * Returns the length of the longest substring without repeating characters.
     *
     * @param s The input string.
     * @return The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(string s) {
        // Initialize variables
        int n = s.size();  // length of the input string
        int i = 0;         // starting index of the current substring
        int j = 0;         // ending index of the current substring
        int ans = 0;       // length of the longest substring

        // Hash map to store the index of the last occurrence of a character
        vector<int> hash(128, -1);

        // Sliding window technique to find the longest substring without
        // repeating characters
        while (j < n) {
            // If the current character is already present in the substring,
            // move the starting index to the right of the last occurrence of
            // the character
            if (hash[s[j]] != -1) {
                i = max(hash[s[j]] + 1, i);
            }

            // Update the hash map and move to the next character
            hash[s[j]] = j;

            // Update the length of the longest substring
            ans = max(ans, j - i + 1);

            // Move to the next character
            j++;
        }

        // Return the length of the longest substring
        return ans;
    }
};
