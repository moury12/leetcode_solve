#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
string reverseWords(string s)
{
    int n = s.length();
    // store final ans here
    string ans = "";
    // first reverse whole sentence
    reverse(s.begin(), s.end());
    /// time complexity O(n)
    for (int i = 0; i < n; i++)
    {
        string word = "";
        // jotokhn projnnto space na pabe loop cholbe and length theke na ber hoye jabe
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        ans += " " + word;
    }
    // jehetu first e ekta space diye add kora hoche aijnno string 1 index theke start hobe not 0 tahole smner extra space minimized
    return ans.substr(1);
}
int main()
{
    string s = "the sky is blue";

    cout << reverseWords(s);
}