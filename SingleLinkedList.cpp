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
class list{

    Node* head;
    Node* tail;
public:
    list(){
        head = tail = NULL;
    }
    // push front 
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            newNode -> next = head;
            head = newNode;
        }
    }
    // push back to linked list
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    // pop front from linked list
    void pop_front(){
        if(head == NULL){
            cout<<" LL is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    // pop back from linked list
    void pop_back(){
        if(head == NULL){
            cout<< " LL is empty"<< endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL){
        temp = temp -> next;  
        }
        temp -> next =  NULL;
        delete tail;
        tail = temp;
    }

    // insert at any postion
    void insertAtPos(int val, int pos){
        if(pos < 0){
            cout<<"invalid postion "<< endl;
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i< pos -1; i++){
           if(temp == NULL){
            cout<<"invalid Postion"<< endl;
            return;
           }
            temp = temp -> next;
        }
        Node* newNode = new Node(val);
        newNode -> next = temp -> next;
        temp -> next = newNode; 
    }

    // search in linked list
    int search(int key){
       
        Node* temp = head;
        int indx = 0;
        while(temp != NULL){
            if(temp -> data == key){
                return indx;
            }
            temp = temp -> next;
            indx++;
        }
      return -1;
    }

    // to print all data of Linked List
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp -> data << " ->";
            temp = temp -> next;
        }
        cout<<"NULL"<< endl;

    }
};


int main(){
    list ll;
    ll.push_front(1);
    ll.push_front(5);
    ll.push_front(9);
    ll.push_back(0);
    // ll.pop_back();
    // ll.pop_front();
    // ll.insertAtPos(100,4);
   cout<< ll.search(87) << endl;
    ll.print();

    return 0;
}
