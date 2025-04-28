//* ZopSmart Technology Round 1

/*
Problem Statement:
Convert String into Nearest Perfect Square ASCII String

You are given a string str consisting of printable ASCII characters (characters with ASCII values between 32 and 126).

Your task is to:

For each character in the string, find its ASCII value.

Replace the character with the character corresponding to the nearest perfect square of its ASCII value.

If the ASCII value is equidistant between two perfect squares, prefer the larger perfect square.

Finally, return the modified string.

Definitions:
A perfect square is an integer that is the square of another integer (e.g., 0, 1, 4, 9, 16, 25, 36, etc.).

Nearest perfect square means the perfect square whose value is closest to the ASCII value.

If two perfect squares are equally close, select the larger one.

Input:
A single string str of length n (1 ≤ n ≤ 10⁵) containing printable ASCII characters.

Output:
Return a new string after replacing each character based on the nearest perfect square rule.

Constraints:
The ASCII value of each character will always be between 32 and 126 inclusive.

You can assume the string contains only standard printable characters (no control characters).

Example 1:
Input:
"ZOPSMART"

Steps:

'Z' → ASCII 90 → Nearest perfect square is 81 (9²) → 'Q'

'O' → ASCII 79 → Nearest perfect square is 81 (9²) → 'Q'

'P' → ASCII 80 → Nearest perfect square is 81 (9²) → 'Q'

'S' → ASCII 83 → Nearest perfect square is 81 (9²) → 'Q'

'M' → ASCII 77 → Nearest perfect square is 81 (9²) → 'Q'

'A' → ASCII 65 → Nearest perfect square is 64 (8²) → '@'

'R' → ASCII 82 → Nearest perfect square is 81 (9²) → 'Q'

'T' → ASCII 84 → Nearest perfect square is 81 (9²) → 'Q'

Output:
"QQQQ@QQQ"

*/

#include <bits/stdc++.h>
using namespace std;

string convertStringIntoNearestPerfectSquare(string &str) {
    const vector<int> perfectSquares = [](){
        vector<int> squares(12);
        for(int i = 0; i <= 11; i++) {
            squares[i] = i * i;
        }
        return squares;
    }();
    
    string ans;
    
    for(char c : str) {
        int num = (int)c;
        auto it = lower_bound(perfectSquares.begin(), perfectSquares.end(), num);
        
        int idx = it - perfectSquares.begin();
        
        if(idx < perfectSquares.size() && perfectSquares[idx] == num) {
            ans.push_back(c);
            continue;
        }
        
        int prev = idx - 1;
        int next = idx;
        
        int diff_prev = (prev >= 0) ? abs(num - perfectSquares[prev]) : INT_MAX;
        int diff_next = (next < perfectSquares.size()) ? abs(perfectSquares[next] - num) : INT_MAX;
        
        if(diff_prev <= diff_next) {
            ans.push_back((char)perfectSquares[prev]);
        } else {
            ans.push_back((char)perfectSquares[next]);
        }
    }
    
    return ans;
}

int main() {
    string str = "ZOPSMART";
    string res = convertStringIntoNearestPerfectSquare(str);
    cout << res << endl;
    return 0;
}