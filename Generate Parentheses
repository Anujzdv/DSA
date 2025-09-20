#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    void backtck(string curr, int open, int close, int n){
        if(curr.size() == n * 2){
            res.push_back(curr);
            return;
        }
        if(open < n){
            backtck(curr + "(", open + 1, close, n);
        }
        if(close < open){
            backtck(curr + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtck("", 0, 0, n);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}
