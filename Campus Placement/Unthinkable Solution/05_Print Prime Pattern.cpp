/*
🧠 Topic: Prime Number Checking using i * i <= n
✅ Definition of Prime Number:
A number is called prime if it has only two distinct positive divisors:

1 and the number itself

Examples: 2, 3, 5, 7, 11, ...

🔍 Logic for Prime Checking:
To check if a number n is prime:

➤ Naive approach:
Check divisibility from 2 to n - 1:


for (int i = 2; i < n; i++)
    if (n % i == 0) return false;
🧨 Time complexity: O(n) → Inefficient for large n

⚡ Optimized Approach: i * i <= n
🔑 Key Insight:
If n is divisible by some number i,
then n = i * j for some j.

If both i and j are > √n, then i * j > n — ❌ impossible

✅ So, if no factors found till √n, then n is prime


✅ Optimized Code (C++):

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

🧠 Why i * i <= num is used (not i <= sqrt(num)):
sqrt() is a floating-point function → less efficient

i * i is faster (integer operation)

No need to include <cmath> library

⏱️ Time Complexity Analysis:
Scenario	    Complexity
Single call     isPrime(n)	O(√n)
Multiple calls for i=1 to n: isPrime(i)	 O(n√n)
Prime check using Sieve of Eratosthenes	 O(n log log n) (for all ≤ n)

🧮 Example:
Check isPrime(29)

i = 2 → 29 % 2 ≠ 0

i = 3 → 29 % 3 ≠ 0

i = 4 → 29 % 4 ≠ 0

i = 5 → 29 % 5 ≠ 0

i * i = 6 * 6 = 36 > 29 → stop loop
✅ No divisors → 29 is prime

📌 When to Use This Approach?
Checking primality of one number → ✅ Use O(√n) method

Checking many numbers up to n → ⚠️ Better to use Sieve

🔁 Your Pattern Printing Code (Brief Idea):

*/

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}
for (int i = 1; i <= n; i++) {
    int count = 0, num = 1;
    while (count < i) {
        if (num == 1 || isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
}