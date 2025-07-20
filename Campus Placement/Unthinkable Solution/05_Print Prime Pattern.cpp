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

---------------------------------------------------------
/*
✅ Sieve of Eratosthenes – Algorithm / Pseudocode
🧠 Idea:
Mark all numbers as prime initially. Then, starting from 2, eliminate all multiples of each prime number (i.e., mark them as not prime).

🔢 Pseudocode:

Function sieve(n):
1. Create a boolean array isPrime[0..n] and initialize all as true
   (isPrime[i] = true means "i is assumed to be prime")
2. Set isPrime[0] and isPrime[1] = false

3. For i from 2 to √n:
    If isPrime[i] is true:
        For j from i*i to n, increment by i:
            → Set isPrime[j] = false

4. All indices i where isPrime[i] is true are prime numbers

🧮 Example for n = 30:
Start with:

isPrime = [false, false, true, true, true, ..., true]
Cross off multiples of 2 → 4, 6, 8, …
Then 3 → 9, 12, 15, …
Then 5 → 25, 30
(We stop at √30 ≈ 5)

Remaining true indices are:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29

🧪 Sample Input/Output:
Input:
n = 30
Output:
Prime numbers up to 30 are:
2 3 5 7 11 13 17 19 23 29
*/

✅ C++ Code: Sieve of Eratosthenes

#include <iostream>
#include <vector>
using namespace std;

void sieve(int n) {
    vector<bool> isPrime(n + 1, true); // index 0 to n
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Output all primes
    cout << "Prime numbers up to " << n << " are:\n";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    sieve(n);

    return 0;
}

Time Complexity -> O(nlog logn)