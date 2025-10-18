class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long pre = LLONG_MIN; 
        int count = 0;

        for (long long x : nums) {
            if (pre < x + k) {
                long long cur = max(x - k, pre + 1); 
                pre = cur;
                count++;
            }
        }
        return count;
    }
};