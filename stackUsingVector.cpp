#include<iostream>
#include <vector>

using namespace std;
class stack{
    vector<int> v;
    public:
    //tc o(1) for all function
    void push(int val){ 
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
        return v[v.size()-1]; // return bcz fun is int type
    }
    bool isEmpty(){
        if(v.size()==0){
            return true;
        }else{
            return false;
        }
    }
};
 
int main()
{
 stack s;
 s.push(10);
 s.push(11);
 s.push(12);
 s.push(13);
 s.push(14);
 //print 
 while(!s.isEmpty()){
    cout<<s.top()<<endl;
    s.pop();
 }
 
return 0;
}
