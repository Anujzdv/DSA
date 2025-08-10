#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int idx = -1;
Node* buildTree(vector<int> preorder){
    idx ++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
   root -> left = buildTree(preorder);
   root -> right = buildTree(preorder);
    return root;
}
// Sum of Node of tree
int SumNode(Node* root){
    if(root == NULL){
        return 0; // empty tree means node is null
    }
    int ltNodeSum = SumNode(root -> left);
    int rtNodeSum = SumNode(root -> right);
    return (ltNodeSum + rtNodeSum + root->data);
}
int main()
{
 vector<int>  preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
 Node* root = buildTree(preOrder);
 cout << "Sum of Node of tree : " << endl;
 cout << SumNode(root);
return 0;
}
