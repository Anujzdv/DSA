#include<iostream>
using namespace std;
class Node{
    public:
     int data;
     Node* next;
     Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;
    public:
    // constructor
     DoublyList(){
        head = tail = NULL;
     }

     void Push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
     }

     void Push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else{
           newNode -> prev  = tail;
           tail -> next = newNode;
           tail = newNode;
        }
     }
     void Pop_front(){
        Node* temp = head;
        head = head -> next;
        if(head == NULL){
            cout<<"LL is Empty" <<endl;
        } else{
            head -> prev = NULL;
        }
        temp -> next = NULL;
        delete temp;
     }

     void pop_back(){
        Node* temp = tail;
        tail = tail -> prev;
        if(head == NULL){
            cout<<"LL is Empty" <<endl;
        } else{
            tail -> next = NULL;
        }
        temp -> prev = NULL;
        delete temp;
     }

     void print(){
        Node* temp = head;
        if(head == NULL){
            cout<<"empty Doubly LL "<< endl;
        }else{
            while(temp != NULL){
                cout<< temp -> data << " <-> " ;
                temp = temp -> next;
            }
            cout<< "NULL";
        }
     }
};
 
int main()
{
 DoublyList ll;
 ll.Push_front(2);
 ll.Push_front(4);
 ll.Push_front(6);
 ll.Push_back(87);
 ll.Push_back(88);
 ll.Pop_front();
 ll.pop_back();
 ll.print();
 
return 0;
}
