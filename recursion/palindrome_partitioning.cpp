#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string s)
{
  string rev = s;
  reverse(rev.begin(), rev.end());
  if (s == rev)
    return true;
  else
    return false;
}
void findPartitions(int idx, string s, vector<vector<string>> &ans, vector<string> &ds)
{
  int n = s.length();
  if (idx == n)
  {
    ans.push_back(ds);
    return;
  }
  for (int i = idx; i < n; i++)
  {
    string partition = s.substr(idx, i-idx+1);
    if (isPalindrome(partition))
    {
      ds.push_back(partition);
      findPartitions(i+1,s,ans, ds);
      ds.pop_back();
    }
  }
}
vector<vector<string>> partition(string s)
{
  vector<vector<string>> ans;
  vector<string> ds;
  findPartitions(0, s, ans, ds);
  return ans;
}
int main()
{
  string s = "aab";
  vector<vector<string>> partitions = partition(s);
  for (auto p : partitions)
  {
    for (auto i : p)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}