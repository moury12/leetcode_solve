#include <iostream>
#include <vector>
using namespace std;
 int maxProfitBruteForce(vector<int>& prices) {
    int n = prices.size();
    int maxP = 0;
        for(int i=0; i<n;i++){
for(int j =i+1;j<n ; j++){
    int profit = prices[j]-prices[i];
    maxP= max(maxP, profit);
}
        }
        return maxP;
    }

int main(){
    vector<int> prices ={7,1,5,3,6,4};
    cout<<maxProfitBruteForce(prices);
}