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
    TreeNode* IS(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        while(root -> left != nullptr){
            root = root -> left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        } else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        } else{
            if(root -> right == nullptr && root -> left == nullptr){
                return nullptr;
            }else if(root -> left == nullptr){
                return root -> right;
            }else if(root ->  right == nullptr){
                return root -> left;
            }else{
                TreeNode* is = IS(root -> right);
                root -> val = is -> val;
                root -> right =  deleteNode(root -> right, is -> val);
            }
        }
        return root;
    }
};