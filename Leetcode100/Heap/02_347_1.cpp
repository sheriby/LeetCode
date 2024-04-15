#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> pairs;
        for (auto it = mp.begin(); it != mp.end(); it++)
            pairs.push_back({it->second, it->first});

        int len = pairs.size();
        build_max_heap(pairs);
        for (int i = len - 1; i > len - k; i--) {
            res.push_back(pairs[0].second);
            swap(pairs[i], pairs[0]);
            max_heapify(pairs, 0, i);
        }
        res.push_back(pairs[0].second);
        return res;
    }

   private:
    void max_heapify(vector<pair<int, int>>& nums, int i, int n) {
        int left = 2 * i + 1, right = 2 * i + 2, large = i;
        if (left < n && nums[left].first > nums[large].first) large = left;
        if (right < n && nums[right].first > nums[large].first) large = right;
        if (large != i) {
            swap(nums[i], nums[large]);
            max_heapify(nums, large, n);
        }
    }

    void build_max_heap(vector<pair<int, int>>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            max_heapify(nums, i, n);
        }
    }
};