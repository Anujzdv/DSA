class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apple = 0;
        for(int i = 0; i< apple.size(); i++){
            total_apple += apple[i];
        }
        sort(capacity.begin(), capacity.end(), greater<int>());
        int res = 0;
        int currcap = 0;
        for(int i = 0; i< capacity.size(); i++){
            currcap += capacity[i];
            res++;
            if(currcap >= total_apple){
                return res;
            }
        }
        return -1;
    }
};