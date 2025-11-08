class Solution {
public:
    int robFrom(vector<int>&nums, int idx, vector<int>&dp){
    if(idx >= nums.size()){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }
    int robb = nums[idx] + robFrom(nums,idx+2,dp);
    int skip = robFrom(nums,idx+1,dp);
    return dp[idx] = max(robb, skip);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> case1 (nums.begin(), nums.end()-1);
        vector<int> dp1(case1.size(), -1);
        int ans1 = robFrom(case1,0,dp1);
        // for case 2
        vector<int> case2 (nums.begin()+1, nums.end());
        vector<int> dp2(case2.size(), -1);
        int ans2 = robFrom(case2,0,dp2);
        return max(ans1, ans2);
    }
};