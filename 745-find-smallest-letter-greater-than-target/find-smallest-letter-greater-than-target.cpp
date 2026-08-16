class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
     vector<int> arr(l.size());
     for(int i =0; i< l.size(); i++){
        arr[i] = l[i]-'a';
     }
     int s = 0, e = arr.size()-1;
     int tr = t -'a';
     int ans = -1;
     while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] > tr){
            ans = arr[mid];
            e = mid -1;
        }else{
            s = mid + 1;
        }
     }
     if(ans == -1){
        return l[0];
     } 
     char c = ans + 'a';
     return c;
    }
};