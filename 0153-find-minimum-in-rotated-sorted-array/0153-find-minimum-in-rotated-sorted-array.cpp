class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int lo = 0, hi = n - 1;
        // pick min from each sorted path
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;

            // we are in left part
            if (nums[mi] >= nums[lo]) {
                ans = min(ans, nums[lo]);
                lo = mi + 1;
            }
            // mi is in ryt part
            else {
                ans = min(ans, nums[mi]);
                hi = mi - 1;
            }
        }
        return ans;
    }
};