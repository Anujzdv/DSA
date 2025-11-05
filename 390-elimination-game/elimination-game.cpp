class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n;
        int step = 1;
        int head = 1;
        while (remaining > 1) {
            if (left || (remaining & 1)) head += step;
            remaining >>= 1;
            step <<= 1;
            left = !left;
        }
        return head;  
    }
};