#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m+n, 0);
        int p = 0, q = 0, i = 0;
        while (p < m && q < n) {
            if (nums1[p] < nums2[q]) 
                tmp[i++] = nums1[p++];
            else 
                tmp[i++] = nums2[q++];
        }
        while (p < m) 
            tmp[i++] = nums1[p++];
        while (q < n) 
            tmp[i++] = nums2[q++];
        
        for (int i = 0; i < m + n; i++) {
            nums1[i] = tmp[i];
        }
        
    }
};

