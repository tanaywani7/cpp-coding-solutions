#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool isValid(const string &t) {
    for (int i = 1; i < t.size(); i++) {
        if (t[i] == t[i - 1]) return false; // adjacent same characters not allowed
    }
    return true;
}

int alternate(string s) {
    set<char> chars(s.begin(), s.end());
    vector<char> unique(chars.begin(), chars.end());
    int maxLength = 0;

    // Try every pair of distinct characters
    for (int i = 0; i < unique.size(); i++) {
        for (int j = i + 1; j < unique.size(); j++) {
            char a = unique[i];
            char b = unique[j];

            string filtered = "";
            for (char c : s) {
                if (c == a || c == b) filtered += c;
            }

            // Check if valid alternating string
            if (isValid(filtered)) {
                maxLength = max(maxLength, (int)filtered.size());
            }
        }
    }

    return maxLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);
    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
