#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortPalindrome' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int shortPalindrome(string s) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
