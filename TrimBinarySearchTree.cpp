#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

// Helper function to print tree inorder
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function to insert nodes into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insertBST(root, 3);
    root = insertBST(root, 0);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 1);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    Solution s;
    int low = 1, high = 3;
    TreeNode* trimmed = s.trimBST(root, low, high);

    cout << "Trimmed BST (Inorder): ";
    inorder(trimmed);
    cout << endl;

    return 0;
}
