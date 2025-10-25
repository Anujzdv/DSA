class Solution {
public:
    int totalMoney(int n) {  
        int fullWeeks = n / 7;
        int remainingDays = n % 7;
        int total = 28 * fullWeeks + 7 * fullWeeks * (fullWeeks - 1) / 2;
        for (int i = 0; i < remainingDays; ++i)
        total += fullWeeks + 1 + i;
        return total;
    }
};