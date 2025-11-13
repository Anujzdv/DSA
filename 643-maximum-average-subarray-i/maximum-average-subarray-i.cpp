class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0;
        int left = 0;
        double ans = -1e18;
        double sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            if(( right - left + 1) > k){
                sum -= nums[left];
                left++;
            }

            if((right - left + 1) == k){
                avg = sum / k;
                ans = max(avg, ans);
            }
        }
        return ans;
    }
};