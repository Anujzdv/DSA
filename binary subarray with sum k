#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;  
        int sum = 0, count = 0;
        
        for (int num : nums) {
            sum += num;
            if (freq.find(sum - goal) != freq.end()) {
                count += freq[sum - goal];
            }
            freq[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;  
    return 0;
}
