#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input = "apple banana cherry";
    stringstream ss(input);
    string word;
    vector<string> result;

    while (ss >> word) {
        result.push_back(word);
    }

    // Output the split words
    for (const string& w : result)
        cout << w << endl;
}

--------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string input = "apple,banana,cherry";
    stringstream ss(input);
    string token;
    vector<string> result;

    while (getline(ss, token, ',')) {
        result.push_back(token);
    }

    for (const string& w : result)
        cout << w << endl;
}