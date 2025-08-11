// next genrator problem it must follow given conditon
// 1. just next greater element availbe 
// 2. if curr el is at the end then return -1;
// 3. if aviable NG then store in ans and also push in STACK

#include<iostream>
#include <vector>
#include <stack>

using namespace std;
 
int main()
{
    vector<int> arr = {6,8,0,1,3};
    int n = arr.size();
    stack<int> s;
    vector<int> NG(n,0); // next genrator initalize with size of arr and with el 0
    // loop from back to front i.e stack (LIFO)
    for(int i = n -1; i>= 0; --i){
        // check for pop the el from stack condition
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();  
        }
        // if no el exit greater than current el in the stack
        if(s.empty()){
                NG[i] = -1;
            } else{
                NG[i]= s.top(); // if avilabe then store in NG (next genertor)
            }
        // finally push the NG in stack for next find NG 
         s.push(arr[i]);
    }
    cout<<" output"<<endl;
    for(int el : NG){
        cout<<el<<" ";
    }

    
return 0;
}
