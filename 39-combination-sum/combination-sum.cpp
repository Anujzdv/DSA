class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& candidates,int i, int target, vector<vector<int>>&res, vector<int> &ans){
    
     if(i == candidates.size() || target < 0){
        return;
     }
      if(target == 0){
        if(s.find(ans) == s.end()){
            res.push_back({ans});
            s.insert(ans);
        }
            return;
        }
    
        ans.push_back(candidates[i]);
        helper(candidates,i+1,target-candidates[i],res,ans); //single enclude
        helper(candidates, i, target - candidates[i], res,ans); // multiple enclude
        ans.pop_back(); // backtracking
        helper(candidates,i+1,target,res,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
         vector<int> ans ;
        helper(candidates,0, target, res,ans);
        return res;
    }
};