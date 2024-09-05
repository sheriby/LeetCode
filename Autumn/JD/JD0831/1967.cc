#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;
    // 智力测试题
    // 当前的元素如何和排序之后的位置为偶数，那么肯定可以通过三个位置旋转的方式得到
    // 只需要攻击位置差为奇数的个数，然后除以2即可
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> nums2(nums);
    sort(nums2.begin(), nums2.end());
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; ++i) mymap[nums2[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (abs(i - mymap[nums[i]]) & 1) cnt++;
    }
    cout << cnt / 2 << endl;
    return 0;
}