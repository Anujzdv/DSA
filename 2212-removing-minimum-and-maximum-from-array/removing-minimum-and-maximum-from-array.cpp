class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int mn = INT_MAX, mx = INT_MIN;
       int mnidx = 0, mxidx = 0;
       for(int i = 0; i< nums.size(); i++){
        if(nums[i] < mn){
            mn = nums[i];
            mnidx = i ;
        }
        if(nums[i]>mx){
            mx = nums[i];
            mxidx = i;
        }
       } 
        int n = nums.size();
        int front = max(mnidx, mxidx) + 1;
        int back = n - min(mnidx, mxidx);
        int both = min(mnidx + 1 + (n - mxidx), mxidx + 1 + (n - mnidx));
        return min({front, back, both});

    }
};