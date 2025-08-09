// insert at haed of circular LL
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
class circularList{
    Node* head;
    Node* tail;
    public:
    circularList(){
        head = tail = NULL;
    }

    void insertHead(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
            tail -> next = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
            tail -> next = head; // or tail -> next = newNode;
            // or we can do this without head Node 
           /*
            newNode -> next = tail -> next;
            tail -> next = newNode;
          */
        }
        
    }

    void insertatEnd(int value){
        Node* newNode = new Node(value);
        if(head == tail){
            head = tail = newNode;

        } else{
            newNode -> next = head;
            tail -> next = newNode;
            tail = newNode; 
        }
        
    }
    void deleteatHead(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head -> next;
            tail -> next = head;
            temp -> next = NULL;
            delete temp;
        }
    }

    void deleteatEnd(){
       if(head == NULL){
            return;
       } else if(head == tail){
            delete head;
            head = tail = NULL;
       } else{
            Node* temp = tail;
            Node* prev = head;
            while(prev -> next != tail){
                prev = prev -> next;
            }
            tail = prev;
            tail -> next = head;
            temp -> next = NULL;
            delete temp;   
       }
    }

    void print(){
        if(head == NULL){
            cout<<"empty Circular LL"<<endl;
            return ;
        }
        cout<< head -> data << " -> " ;
        Node* temp = head -> next;
        while(temp != head ){
            cout<<temp -> data <<" -> ";
            temp = temp -> next;
        }
        cout<< temp -> data <<endl;
    }
};
 
int main()
{
    circularList cl;
    cl.insertHead(8);
    cl.insertHead(6);
    cl.insertatEnd(100);
    cl.insertatEnd(120);
    // cl.deleteatHead();
    // cl.deleteatHead();
    // cl.deleteatHead();
    // cl.deleteatHead();
     cl.print();
     cout<<endl;
    cl.deleteatEnd();
    cl.deleteatEnd();
    cl.print();
    
return 0;
}
