class Solution {
public:
    string removeDuplicateLetters(string s) {
    vector<int> f(256,0);
    vector<int> v(256,0);
    for(char c:s) f[c]++;
    string st="";
    for(char c:s){
        f[c]--;
        if(v[c]) continue;
        while(!st.empty()&&st.back()>c&&f[st.back()]>0){
            v[st.back()]=0;
            st.pop_back();
        }
        st.push_back(c);
        v[c]=1;
    }
    return st;
    }
};