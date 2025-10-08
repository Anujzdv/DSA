/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(vector<int>&io, int s, int e){
        if(s>e){
            return nullptr;
        }
        int mid = (s + e )/2;
        TreeNode* root = new TreeNode(io[mid]);
        root -> left = build(io,s,mid-1);
        root -> right = build(io,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> io;
        ListNode* temp = head;
        while(temp != nullptr){
            io.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = io.size();
        TreeNode* root = nullptr;
        if(n==0){
            return nullptr;
        }
        return build(io,0,n-1);
    }
};