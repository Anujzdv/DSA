/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &mountainArr){
        int s = 0, e = mountainArr.length()-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s = mid +1;
            }else{
                e = mid -1;
            }
        }
        return s;
    }
    int s(int target, MountainArray &mountainArr, int k){
        int s = 0, e = k, ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(mountainArr.get(mid) == target){
                ans =  mid;
                break;
            }
            else if(mountainArr.get(mid) < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return ans;
    }
     int s1(int target, MountainArray &mountainArr, int k){
        int s = k+1, e = mountainArr.length()-1, ans = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(mountainArr.get(mid) == target){
                ans =  mid;
                break;
            }
            else if(mountainArr.get(mid) < target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        // if(ans != -1){
        //     ans = ans + k +1 ;
        // }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int k = peak(mountainArr);
        int x = s(target,mountainArr,k);
        int y = s1(target,mountainArr,k);
        int ans  = -1;
        if(x == -1){
            ans = y;
        }else if( y == -1){
            ans = x;
        }else{
            ans = min(x,y);
        }
        return ans;
    }
};