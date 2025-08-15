// * Power Of Two (2)

//Approach-1 (Using normal division) - Can also wite iterative version
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        return n%2 == 0 && isPowerOfTwo(n/2);
    }
};

//Approach-2 (Using bit magic)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

//Approach-2 (__builtin_popcount)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        return __builtin_popcount(n) == 1;
    }
};


// * Power Of Three (3)

//Approach-1 (simply dividing and checking iteratively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
          
        while(n%3 == 0) {
            n /= 3;
        }
          
        return n == 1;  
    }
};


//Approach-2 (simply dividing and checking recursively)
//T.C : O(log3(n))
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }
        else if(n == 1) {
            return true;
        }
        return n%3 == 0 && isPowerOfThree(n/3);  
    }
};



//Approach-3 (simply checking with largest valid power of 3)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
        //NOTE :  3^19 = 1162261467
    }
};



//Approach-4 (Using logarithms and checking if log base 3 of n is an integer)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        double logValue = log10(n) / log10(3);

        // Check if logValue is an integer
        return logValue == (int)logValue;
    }
};

// * Power Of Four (4)

bool isPowerOfFour(int n) {
    return n > 0 && (n & (n - 1)) == 0 && ((n - 1) % 3) == 0;
}

bool isPowerOfFour(int n) {
    if(n <= 0)return false;
    double x = log10(n) / log10(4);
    return x == (int) x;
}