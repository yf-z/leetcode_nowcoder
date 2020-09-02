/*
*   Written By
*   Yifan Zhang
*/

/*
*   一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
*   求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


class Solution {
public:
    int jumpFloorII(int number) {
        return dp(number);
    }
    
    int dp(int number) {
         int steps[number];
         int sum = 0;
         for (int i = 0; i < number; i++) {
             steps[i] = 0;
         }
         if (number > 0) {
             steps[0] = 1;
         }
         
         if (number > 1) {
             steps[1] = 2;
             sum = 3;
             for (int i = 2; i < number; i++) {
                 steps[i] = sum + 1;
                 sum += steps[i];
             }
         }
         
         return steps[number-1];
     }
};