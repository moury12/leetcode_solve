#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    vector<int> ans = {};
    int n = grid.size();
    unordered_map<int, int> um;
    int a;
    int sumOfGrid = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            sumOfGrid += grid[i][j];
            if(um.find(grid[i][j])!=um.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            um[grid[i][j]]++;
            // um[grid[i][j]]++;
        }
    }

    // for (auto i : um)
    // {
    //     if (i.second > 1)
    //     {
    //         a = i.first;
    //         ans.push_back(i.first);
    //         break;
    //     }
    //     cout << "dfsdf" << i.first << "  " << i.second << endl;
    // }
    int N = n * n;
    int actualSum = (N * (N + 1)) / 2;

    // cout << "actual sum " << actualSum << endl;
    // cout << "grid sum " << sumOfGrid << endl;
    ans.push_back((actualSum + a) - sumOfGrid);
    return ans;
}
int main()
{
    // num range hobe n^2 prjnnto eikhne n=2 so 4
    vector<vector<int>> grid = {{1, 3},
                                {2, 2}};

    vector<int> ans = findMissingAndRepeatedValues(grid);
    for (int i : ans)
    {
        cout << i << endl;
    }
    return 0;
}