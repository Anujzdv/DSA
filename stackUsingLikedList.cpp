#include<iostream>
#include<list>
using namespace std;
class stack{
    list<int> ll;
    public:
    
    void push(int val){
        ll.push_front(val);
    }
    void pop(){
        ll.pop_front();
    }
    int top(){
        return ll.front(); // return bcz functionn is int type
    }
    bool isEmpty(){
        return (ll.size()==0);
    }
};
 
int main()
{
 stack s;
 s.push(100);
 s.push(101);
 s.push(102);
 s.push(103);
 s.push(104);
 s.push(105);
 while(!s.isEmpty()){
    cout<< s.top()<<endl;
    s.pop();
 }
return 0;
}
