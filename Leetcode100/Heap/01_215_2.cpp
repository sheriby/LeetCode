#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Solution class for the Kth Largest Element problem.
 * This class implements a method to find the k-th largest element in an
 * unsorted array.
 */
class Solution {
   public:
    /**
     * Finds the k-th largest element in the given unsorted array.
     *
     * @param nums the input array
     * @param k the index of the k-th largest element to find
     * @return the k-th largest element
     */
    int findKthLargest(vector<int>& nums, int k) {
        // Build a max heap from the input array
        build_max_heap(nums);
        // Reverse the heap order and heapify to get the k-th largest element
        for (int i = nums.size() - 1; i > nums.size() - k; i--) {
            swap(nums[0], nums[i]);  // Move the k-th largest element to the top
            max_heapify(nums, 0, i);  // Heapify the remaining elements
        }

        // Return the k-th largest element
        return nums[0];
    }

   private:
    /**
     * Heapifies a sub-array of the input array.
     *
     * @param nums the input array
     * @param i the index of the parent node
     * @param n the size of the sub-array
     */
    void max_heapify(vector<int>& nums, int i, int n) {
        int l = 2 * i + 1;  // Left child index
        int r = 2 * i + 2;  // Right child index
        int largest = i;    // Initialize the largest index as the parent

        // Find the largest between the parent, left child, and right child
        if (l < n && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < n && nums[r] > nums[largest]) {
            largest = r;
        }

        // If the parent is not the largest, swap it with the largest child and
        // heapify recursively
        if (largest != i) {
            swap(nums[i], nums[largest]);
            max_heapify(nums, largest, n);
        }
    }

    /**
     * Builds a max heap from the input array.
     *
     * @param nums the input array
     */
    void build_max_heap(vector<int>& nums) {
        int n = nums.size();

        // Heapify the array from the last non-leaf node to the root
        for (int i = n / 2 - 1; i >= 0; i--) {
            max_heapify(nums, i, n);
        }
    }
};
