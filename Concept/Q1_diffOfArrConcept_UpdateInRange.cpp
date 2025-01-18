
/*

leetcode - 2381. https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05 

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.size();

        vector<int> arr(n, 0);

        for (auto& query : shifts) {

            int start = query[0];
            int end = query[1];
            int val = query[2] == 0 ? -1 : 1;

        
            arr[start] += val;

            if (end + 1 < n) {
                arr[end + 1] -= val;
            }
        }

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int num = (s[i] - 'a' + arr[i]) % 26;
            num = (num + 26) % 26;
            s[i] = (char)(num + 'a');
        }
        return s;
    }
};

*/