#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class LL{
    Node* head;
    Node* tail;
public:
    LL(){
        head = NULL;
        tail = NULL;
    }
    void insert(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }

    }
    void print(){
        if(head == NULL){
            cout<<"empty Linked List"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout<<temp -> data<< "->" ;
            temp = temp -> next;
        }
        cout<<"NULL";
    }
    // brutforce approach 
    void middle(){
        if(head == NULL){
            cout<<"empty LinkedList"<<endl;
            return;
        }
        Node* temp = head;
        int size = 0;
        int mid = -1;
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
        int middle;
        if(size % 2 == 0){
            middle = size/2 + 1;
        }else{
            middle = (size+1)/2;
        }
        temp = head;
        for(int i = 0; i< middle ; i++ ){
           
            if(i == middle - 1){
                cout<< " middle element is : "<< temp -> data<<endl;
            }
            temp = temp -> next;
        }
    
    }
    // best approach (slow and fast pointer)
    void mid(){
        Node* slow = head; // it move one step at a time.
        Node* fast = head; // it move two step at a time.
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // slow give the middle postion of LL.
        cout<<" middle element is (mid fun) : "<< slow-> data<< endl;
    }
};

int main(){
    LL myll;
    myll.insert(29);
    myll.insert(12);
    myll.insert(13);
    myll.insert(11);
    myll.insert(16);
    myll.insert(19);
    myll.middle();
    myll.mid();
    myll.print();

return 0;
}
