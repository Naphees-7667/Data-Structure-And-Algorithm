// ! T.C = O(n*n)   where n for traversing * n for traversing again at the time of closing bracket

// ! S.C = O(n) stack space and map space

/*
Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

For example, "(H2O2)" and "(H2O2)3" are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

*/


// * Leetcode - 726. NumberOfAtoms

/* 
Approach - store map inside stack and and 1.opening bracket - insert empty map
2.closing bracket mai do all stuffs according to que and merge them on stack top 
3.otherwise direct compute element name and count 
*/

// ! Important Keyword 
/*
1. char - '0' -> convert single char into single digit
2. char + '0' -> convert single digit into single character
3. stoi(str) -> convert string into integer  
4. isalpha(ch) -> check whether ch is character or not  
5. islower(ch) -> check whether ch is lowercase or not 
6. to_string(num) -> convert num into string
*/

#include<bits/stdc++.h>
using namespace std;

string countOfAtoms(string formula) {

    int n = formula.length();

    stack< unordered_map<string, int> > st;
    st.push(unordered_map<string,int>());

    int i = 0;
    while(i < n){
        if(formula[i] == '('){
            st.push(unordered_map<string,int>());
            i++;
        }
        else if(formula[i] == ')'){
            unordered_map<string,int> curr = st.top();
            st.pop();
            i++;

            string mult;
            while((i < n) && isdigit(formula[i])) {
                mult.push_back(formula[i]);
                i++;
            }

            if(!mult.empty()){
                int multInteger = stoi(mult);
                for(auto &it : curr){
                    string element = it.first;
                    int count = it.second;

                    curr[element] = count * multInteger;

                }
            }

            //merging this in the stack's top 

            for(auto &it : curr){
                string element = it.first;
                int count = it.second;
                st.top()[element] += count;
            }

        }
        else{

            string currElement;
            currElement.push_back(formula[i]);
            i++;

            while(i < n && isalpha(formula[i]) && islower(formula[i])){
                currElement.push_back(formula[i]);
                i++;
            }

            string currCount;
            while(i < n && isdigit(formula[i])){
                currCount.push_back(formula[i]);
                i++;
            }

            int currCountInteger = currCount.empty() ? 1 : stoi(currCount);
            st.top()[currElement] += currCountInteger;
        }
    }

    //st will only have one lement (one map on top)

    map<string, int> sortedMap(begin(st.top()),end(st.top()));
    st.pop();

    string result;

    for(auto &it : sortedMap){
        string element = it.first;
        result += element;
        int count = it.second;
        result += (count > 1) ? to_string(count) : "";
    }
    return result;
}