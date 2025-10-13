#include <iostream>
#include <vector>
using namespace std;
/// time complexity n^2
/// space complexity constant
int maxProfitBruteForce(vector<int> &prices)
{
    int n = prices.size();
    int maxP = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int profit = prices[j] - prices[i];
            maxP = max(maxP, profit);
        }
    }
    return maxP;
}
/// every index value suppose selling price and from 0 - i-1 need to find min selling amount
/// time complexity here O(n)

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxP = 0;
    int bestBuy = prices[0];
    for (int i = 0; i < n; i++)
    {
        if (prices[i] > bestBuy)
        {
            int profit = prices[i] - bestBuy;
            maxP = max(maxP, profit);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxP;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
}