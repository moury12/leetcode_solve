#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
///container needs left right boundary so when left boundary at index 2 right boundary index need to more 
///than 2 . so water will be hold to short bondary 
int maxAreaBruteForce(vector<int>& height) {
    int ans=0;
    int maxWater =0;
        for(int i =0; i<height.size();i++){
            for (int j =i+1 ;j<height.size();j++){
int heightWater= min(height[i], height[j]);
int width= j-i;
int ans =heightWater*width;
maxWater = max(maxWater,ans);

            }
        }
        return maxWater;
    }
int main(){
vector<int> heights={1,8,6,2,5,4,8,3,7};
cout <<maxAreaBruteForce(heights);
}