#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> m1(256, -1), m2(256, -1);
        for(int i = 0; i < s.size(); i++) {
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    Solution sol;
    if(sol.isIsomorphic(s, t)) cout << "true\n";
    else cout << "false\n";
    return 0;
}
