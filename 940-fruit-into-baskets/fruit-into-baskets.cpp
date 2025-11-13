class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 1){
            return 1;
        }
        int left = 0;
        int ans = 0;
        unordered_map<int, int> f;
        for(int right = 0; right < n; right++){
            f[fruits[right]]++;
            if(f.size() > 2){
                f[fruits[left]]--;
                if(f[fruits[left]] == 0){
                    f.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};