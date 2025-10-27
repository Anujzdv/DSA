class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,vector<int>& ans, int i){
        if( i == nums.size()){
            res.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        helper(nums, ans, i+1);
        ans.pop_back();
        helper(nums, ans, i+ 1);
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        helper(nums, ans, 0);
        return res;
    }
};