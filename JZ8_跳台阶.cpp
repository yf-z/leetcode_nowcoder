/*
*   Written By
*   Yifan Zhang
*/

/*
*   一只青蛙一次可以跳上1级台阶，也可以跳上2级。
*   求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
    int jumpFloor(int number) {
        return dp(number);
    }
    
     int dp(int number) {
         int steps[number];
         for (int i = 0; i < number; i++) {
             steps[i] = 0;
         }
         if (number > 0) {
             steps[0] = 1;
         }
         
         if (number > 1) {
             steps[1] = 2;
             for (int i = 2; i < number; i++) {
                 steps[i] = steps[i-1]+steps[i-2];
             }
         }
         
         return steps[number-1];
     }
};