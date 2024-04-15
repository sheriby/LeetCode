#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // i -> nums[i]
    // 最多n-1个节点，n条边，说明肯定是有环的,
    // nums[i]的入度为2，环的入口为nums[i]，利用快慢指针找到环的入口即可
    // 1 3 2 4 2
    // 0 -> 1 -> 3 -> 4 -> 2 -> 2
    // M + N + C = 2 (M + C) = 2M + 2C => M = N - C
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        // 先让快慢指针相遇
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        // 快指针回到起点，速度也变成慢指针，相遇的地方就是环的入口
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};