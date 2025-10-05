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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return {};
        }
        return build(1,n);
    }
private:
    vector<TreeNode*> build(int s, int e){
        vector<TreeNode*> res;
        if(s > e){
            res.push_back(nullptr);
            return res;
        }
        for(int i = s; i <= e; i++){
            vector<TreeNode*> ltsub = build(s,i-1);
            vector<TreeNode*> rtsub = build(i+1,e);
            for(auto lt : ltsub){
                for(auto rt : rtsub){
                    TreeNode* root = new TreeNode(i);
                    root -> left = lt;
                    root -> right = rt;
                    res.push_back(root);
                }
            }

        }
        return res;
    }
};