/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inor(TreeNode* root, vector<int>&res){
        if(root == nullptr){
            return;
        }
        inor(root -> left,res);
        res.push_back(root -> val);
        inor(root -> right,res);
    }
    vector<int> findMode(TreeNode* root) {
       vector<int> res;
       inor(root,res);
        unordered_map<int,int> f;
        for(int i : res){
            f[i]++;
        }
        int maxf = INT_MIN;
        for(auto &i : f){
            if(i.second > maxf){
                maxf = i.second;
            }
        }
        vector<int> ans;
        for(auto &i : f){
            if(i.second == maxf){
                ans.push_back(i.first);
            }
        }
        return ans; 
    }
};