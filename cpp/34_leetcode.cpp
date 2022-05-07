// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int lbin(vector<int>& nums, int target){
        int m, l=0, r=nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return (l < nums.size() and nums[l]==target) ? l : -1;
    }
    
    int rbin(vector<int>& nums, int target){
        int m, l=0, r=nums.size() - 1;
        while (l <= r) {
            m = (l + r + 1) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return (r < nums.size() and nums[r]==target) ? r : -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx_left, idx_right;
        
        idx_left = lbin(nums, target);
        idx_right = rbin(nums, target);
        
        vector<int> res {idx_left, idx_right};
        return res;
    }
};
