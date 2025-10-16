class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            int r = ((num % value) + value) % value;
            freq[r]++;
        }
        int ans = 0;
        while (true) {
            int r = ans % value;
            if (freq[r] == 0) return ans;
            freq[r]--;
            ans++;
        }  
    }
};