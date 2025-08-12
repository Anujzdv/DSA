#include<iostream>
#include<vector>
#include<queue>
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
Node* buildTree(vector<int> preOrder){
    idx ++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preOrder[idx]);
    root -> left = buildTree(preOrder); // for left subTree
    root -> right = buildTree(preOrder); // for right subTree
    return root;
}
// pre-order traversal ( Root , Lt, Rt)
void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}
// inorder traversal (Lt, Root , Rt)
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout<< root -> data << " ";
    inorder(root -> right);
} 
// Postorder traversal (Lt, Rt , Root)
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    inorder(root -> right);
    cout<< root -> data << " ";
} 
// Level Order Traversal (level wise traversal from top to bottom)
void LevelOrder(Node* root){
    queue<Node*> Q;
    Q.push(root);
    while(Q.size() > 0){
        Node* curr = Q.front();
        Q.pop();
        cout<< curr -> data << " ";
        if(curr -> left != NULL){
            Q.push(curr -> left);
        }
        if(curr -> right != NULL){
            Q.push(curr -> right);
        }
    }
}
// Level Order Traversal (level wise print line by line )
void LevelOrderLineWise(Node* root){
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(Q.size() > 0){
        Node* curr = Q.front();
        Q.pop();
        if(curr == NULL){
            if(!Q.empty()){
                cout<< endl;
                Q.push(NULL);
                continue;
            } else{
                break;
            }
        }
        cout<< curr -> data << " ";
        if(curr -> left != NULL){
            Q.push(curr -> left);
        }
        if(curr -> right != NULL){
            Q.push(curr -> right);
        }
    }
}
int main()
{
 vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
 Node* root = buildTree(preOrder);
//  cout<< root -> data << endl;
//  cout<<" end" << endl;
cout << "preorder traversal" << endl;
preorder(root);
cout <<endl<< "inorder traversal " << endl;
inorder(root);
cout <<endl<< "Postorder traversal " << endl;
postorder(root);
cout <<endl<< "Level order traversal " << endl;
LevelOrder(root);
cout <<endl<< "Level order traversal Level Wise " << endl;
LevelOrderLineWise(root);
return 0;
}
