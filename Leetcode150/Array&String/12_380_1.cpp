#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class RandomizedSet {
   public:
    unordered_set<int>* set;
    RandomizedSet() { set = new unordered_set<int>(); }

    bool insert(int val) {
        if (set->count(val))
            return false;
        else {
            set->insert(val);
            return true;
        }
    }

    bool remove(int val) {
        if (set->count(val)) {
            set->erase(val);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() {
        int n = rand() % set->size();
        auto res = set->begin();
        for (int i = 0; i < n; i++) {
            res++;
        }
        return *res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */