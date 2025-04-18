class Solution {
public:

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);

        for(int i=0; i<n; i++)
        {
            for(int j=1; j<=1001; j++)
            {
                if((j | (j + 1)) == nums[i])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};