#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 首先从右面向左找到第一个不是降序的数字
    // 然后从这个数字向右面找到大于他的最小的数字交换 p.s.
    // 此时这个数字后面已经是一个降序的序列，从后面找到第一个大于这个数字的数字交换即可
    // 直到找不到也就是后面已经是逆序了，通过reverse将其变成正序
    // 4 5 2 6 3 1
    // find 2 => find 3 swap => 4 5 3 6 2 1 => reverse => 4 5 3 1 2 6
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        return;
        int i = len - 2;
        // 第一个不是降序的数字，也就是 num[i] < num[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;

        // 为-1，则说明这个序列都是逆序的，这是最大的序列，直接reverse就行了
        if (i >= 0) {
            int j = len - 1;
            while (j > i && nums[j] <= nums[i]) --j;
            // 此时 nums[j] > nums[i]
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};