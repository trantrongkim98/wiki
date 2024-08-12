
#include "stdio.h"
#include "stdbool.h"
#define false 0
#define true 1 // Option 1

/*
You are climbing a staircase that has n steps, and you want to climb to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps + 1 step

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step + 1 step

Constraints:
`1 <= n <= 45`

Solution:
when you use one 2steps at n = 7, and then you have n = 6
when you use one 2steps at n = 6, and then you have n = 5
when you use one 2steps at n = 5, and then you have n = 4
when you use one 2steps at n = 4, and then you have n = 3
when you use one 2steps at n = 3, and then you have n = 2
when you use one 2step2 at n = 2, and then you have n = 1
Because result of 7 = 
Conclude:
The result of n = s(n-1) + s(n-2)
*/

int climbStairs(int n){
    if(n<=0) return 0;
    if(n == 1) return 1;
    if(n==2) return 2;
    int previous2 = 1;
    int previous1 = 2;
    int step = 3;
    while(step < n){
        int temp = previous1 + previous2;
        previous2 = previous1;
        previous1 = temp;
        step ++;
    }
    return previous2 + previous1;
}
int main() {
    int diff = climbStairs(45);
    printf("%d\n", diff);
    return 0;
}