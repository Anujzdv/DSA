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
// traversal the node of the given tree
    vector<int> elements;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root -> left);
        elements.push_back(root -> val);
        inorder(root -> right);
    }

// build tree
    TreeNode* build(int s, int e){
        if(s > e) return nullptr;
        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(elements[mid]);
        root -> left = build(s, mid - 1);
        root -> right = build(mid + 1, e);
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, elements.size()-1);
    }
};