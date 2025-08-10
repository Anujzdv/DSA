#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root -> left = buildTree(preorder);
    root -> right = buildTree(preorder);
    return root;
}

void kLevelEl(Node* root, int K){
    if(root == NULL){
        return;
    }
    if(K == 1){
        cout << root -> data << " ";
        return;
    }
    kLevelEl(root -> left, K - 1);
    kLevelEl(root -> right, K - 1);

}
 
int main()
{
vector<int>  preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
 Node* root = buildTree(preOrder);
 kLevelEl(root,2);
return 0;
}
