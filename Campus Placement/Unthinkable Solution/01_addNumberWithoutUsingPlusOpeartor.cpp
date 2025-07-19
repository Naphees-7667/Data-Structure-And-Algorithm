/* 
✅ Approach: Add Two Numbers Without + Operator
We use bitwise XOR and AND operations to simulate addition:

🔧 Key Bitwise Operations:
XOR (^) – gives sum without carry

a ^ b adds bits where only one is 1 (like addition without carry).

AND (&) + Left Shift (<< 1) – gives carry

a & b finds positions where both bits are 1 (which causes a carry).

Shifting left by 1 moves the carry to the correct position.

Repeat until carry is 0

We repeat the process: calculate new sum and carry until there's no carry left.

✅ Step-by-Step Example (Add 3 + 5)
a = 3 (011), b = 5 (101)

Step 1:

sum = a ^ b = 011 ^ 101 = 110 (6)

carry = (a & b) << 1 = (001) << 1 = 010 (2)

Step 2:

a = 6, b = 2

sum = 110 ^ 010 = 100 (4)

carry = (110 & 010) << 1 = (010) << 1 = 100 (4)

Step 3:

a = 4, b = 4

sum = 100 ^ 100 = 000 (0)

carry = (100 & 100) << 1 = (100) << 1 = 1000 (8)

Step 4:

a = 0, b = 8

sum = 0 ^ 8 = 8

carry = 0

Final Result = a = 8

*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b;         // sum without carry
            int carry = (a & b) << 1; // carry
            a = sum;
            b = carry;
        }
        return a;
    }
};