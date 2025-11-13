class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> f;
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++){
            f[s[right]]++;
            while(f[s[right]]  > 1){
                f[s[left]]--;
                if(f[s[left]] == 0){
                    f.erase(s[left]);
                }
                left++;
            }
            ans = max(ans , right - left + 1);
        }
        return ans;
    }
};