class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(string c : operations){
            if(c == "--X"){
                --res;
            }else if(c == "X--"){
                res--;
            }else if(c == "X++"){
                res++;
            }else if (c == "++X"){
                ++res;
            }
        }
        return res;
    }
};