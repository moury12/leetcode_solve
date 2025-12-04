#include <iostream>
using namespace std;
#include <String>
bool check(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{
    int freq1[26] = {};
    int freq2[26] = {};
    if (s1.length() > s2.length())
    {
        return false;
    }
    int windowSize = s1.length();
    for (int i = 0; i < windowSize; i++)
    {
        freq2[s2[i] - 'a']++;
        // its works like 0th index a 1th index b 25th index z so if gfh then g=1, f=1, h=1 others remain zero

        freq1[s1[i] - 'a']++;
    }
    if (check(freq1, freq2))
    {
        return true;
    }
    for (int i = windowSize; i < s2.length(); i++)
    {

        freq2[s2[i] - 'a']++;
        int leftIndex = i - windowSize;
        freq2[s2[leftIndex] - 'a']--;
        if (check(freq1, freq2))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
}
