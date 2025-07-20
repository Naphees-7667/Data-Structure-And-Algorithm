/*
Question - 1
Count the Reversals

Given a string s consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression. A reversal means changing '{' to '}' or vice-versa.

Examples:

Input: s = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

Input: s = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/

class Solution {
  public:
    int countMinReversals(string s) {
        if(s.size() % 2 == 1) return -1;
        int open = 0, close = 0;
        for(auto &ch : s){
            if(ch == '{'){
                open++;
            }
            else if(open >= 1){
                open--;
            }
            else close++;
        }
        
        return ((open + 1) / 2 ) + ((close + 1) / 2);
    }
};

--------------------------------------------------------------------------------

/*
Minimum Swaps for Bracket Balancing

You are given a string s of 2*n characters consisting of n ‘[‘ brackets and n ‘]’ brackets. A string is considered balanced if it can be represented in the form a[b] where a and b are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings a and b can be empty.

Examples :

Input: s = "[]][]["
Output: 2
Explanation: First swap: Position 3 and 4 [][]][, Second swap: Position 5 and 6 [][][]

Input: s = "[][]"
Output : 0 
Explanation: String is already balanced.
Input: s = "[[[][][]]]"
Output: 0 
*/

int miniNumSwaps(string& brackets, int n) {
    int  open = 0, ans = 0;
    for(int i = 0; i < brackets.size(); i++){
        if(brackets[i] == '['){
            open++;
        }
        else{
            open--;
            if(open < 0) ans -= open;
        }
    }

    return ans;
}

--------------------------------------------------------------------------------
/*
678. Valid Parenthesis String

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
 

Constraints: 1 <= s.length <= 100

Approach -> we can use dynamic programming also but normally we can solve this using range based concept like we do in the jump game2 question  
*/

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;

        for(auto &it : s){
            if(it == '('){
                mini++;
                maxi++;
            }   
            else if(it == ')'){
                mini--;
                maxi--;
            }
            else{
                maxi++;
                mini--;
            }
            if(mini < 0)mini = 0;
            if(maxi < 0)return false;
        }
        return mini == 0;
    }
};

--------------------------------------------------------------------------------

/*
2116. Check if a Parentheses String Can Be Valid

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

Example 1:
Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.

Example 2:
Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.

Example 3:
Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0]. 
Changing s[0] to either '(' or ')' will not make s valid.

Example 4:
Input: s = "(((())(((())", locked = "111111010111"
Output: true
Explanation: locked permits us to change s[6] and s[8]. 
We change s[6] and s[8] to ')' to make s valid.
*/

// * First Approach -  traverse from the both side of the string 

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                open++;
            } else
                open--;
            if (open < 0) // open can not be negative we we use same variable to checking from starting we we have open bracket we increase count and when we have close bracket then we decrease the count if count become negative then it is not possible to make string valid

                return false;
        }
        int close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                close++;
            } else
                close--;
            if (close < 0)
                return false;
        }
        return true;
    }
};

// * 2nd Approach -> solve it using range based approach  just like we have done in previous question  

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int mini = 0;
        int maxi = 0;

        if (s.size() % 2 != 0) return false;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '1' && s[i] == '(') {
                mini++;
                maxi++;
            } else if (locked[i] == '1' && s[i] == ')') {
                mini--;
                maxi--;
            }
            else {
                mini--;
                maxi++;
            }
            if (mini < 0)mini = 0;

            if (maxi < 0)return false;
        }
        return mini == 0;
    }
};