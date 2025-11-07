class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // Brute Force Approach
      unordered_map<int,int> freq;
      for(int i = 0; i< nums.size(); i++){
        freq[nums[i]]++;
      } 
      vector<int> ans;
    vector<pair<int, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    });
    for(int i = 0; i < k ; i++){
        ans.push_back(vec[i].first);
    }
    return ans;
    }
};