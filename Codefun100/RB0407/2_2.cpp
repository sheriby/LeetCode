#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
// 从评论从大到小开始，计算大于该评论的k-1个点赞最大之和
int main() {
    int n, k;
    cin >> n >> k;
    vector<PII> nums(n);  // (comment, like)
    for (int i = 0; i < n; ++i) cin >> nums[i].first;
    for (int i = 0; i < n; ++i) cin >> nums[i].second;
    // sum(like) * min(comment)
    sort(nums.begin(), nums.end(),
         [](auto a, auto b) { return a.second > b.second; });

    // 小顶堆存放最大的k-1个点赞
    priority_queue<int, vector<int>, greater<int>> q;
    int max_val = 0, like, com, sum = 0;
    for (int i = 0; i < n; ++i) {
        like = nums[i].first;
        com = nums[i].second;
        q.push(like);
        sum += like;
        // 此时可以制作笔记合集
        if (i >= k - 1) {
            max_val = max(max_val, sum * com);
            // 维护堆的大小，去掉堆顶最小的元素
            sum -= q.top();
            q.pop();
        }
    }
    cout << max_val << endl;
    return 0;
}