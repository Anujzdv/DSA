class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int>st;
        st.push(0);
        for(int el : nums){
            while (!st.empty() && st.top() > el){
                st.pop();
            }
            if (st.empty() || st.top() < el) {
                ans++;
                st.push(el);
            }
        }
        return ans;
    }
};