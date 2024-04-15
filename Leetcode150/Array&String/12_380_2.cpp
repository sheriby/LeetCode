#include <algorithm>
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
   public:
    RandomizedSet() { srand((unsigned int)time(NULL)); }

    bool insert(int val) {
        if (maps.count(val)) return false;
        maps[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!maps.count(val)) return false;
        int idx = maps[val];
        int last = nums.back();
        nums[idx] = last;
        maps[last] = idx;
        maps.erase(val);
        nums.pop_back();
        return true;
    }

    int getRandom() {
        int n = rand() % nums.size();
        return nums[n];
    }

   private:
    vector<int> nums;
    unordered_map<int, int> maps;
};
