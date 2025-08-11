#include<iostream>
#include<stack> // direct use stack without vector or LL
using namespace std;
 
/* some of stack method
   push
   pop
   top
   empty
*/
int main()
{
 stack<int> s; // intialize stack
 s.push(12);
 s.push(34);
 s.push(56);
 s.push(78);
 s.pop();
 while(!s.empty()){
    cout<< s.top()<<endl;
    s.pop();
 }
 
return 0;
}
